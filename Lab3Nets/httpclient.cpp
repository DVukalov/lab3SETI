#include <QDebug>
#include <QByteArray>

#include "httpclient.h"
#include "httpclient_p.h"

// Необходимые макро-определения
#define request "GET /enp/rfc/rfc128.txt HTTP/1.0\r\nHost: " \
    "www.networksorcery.com\r\n\r\n" 	// HTML запрос.

// www.networksorcery.com/enp/rfc/rfc227.txt

#define MAX_PACKET_SIZE 1024

#define REQUEST(arg1, arg2) QByteArray(\
    QString("GET %1 HTTP/1.0\r\nHost: " \
    "%2\r\n\r\n").arg(arg1, arg2).toUtf8())


HTTPClient::HTTPClient(QObject *parent)
    : QObject(parent)
    , d_ptr(new HTTPClientPrivate(parent))
{
    Q_D(HTTPClient);
    d->q_ptr = this;
}

HTTPClient::~HTTPClient()
{
    d_ptr->deleteLater();
}

bool HTTPClient::isValid()
{
    Q_D(HTTPClient);
    return d->mValid;
}

void HTTPClient::interrupt()
{
    Q_D(HTTPClient);
    if(d->pThread->isRunning())
        d->pThread->requestInterruption();
}

void HTTPClient::getData(QByteArray link)
{
    Q_D(HTTPClient);
    int index = link.indexOf("/");

    d->mCurrentSite.resize(index);
    d->mCurrentPath.resize(link.size() - index);

    qCopy(link.begin(), link.begin() + index,
          d->mCurrentSite.begin());
    qCopy(link.begin() + index, link.end(),
          d->mCurrentPath.begin());

    __print << d->pThread->isRunning();
    while(d->pThread->isRunning())
        d->pThread->requestInterruption();

    d->pThread->start();
}

HTTPClientPrivate::HTTPClientPrivate(QObject *parent)
    : QObject(parent)
    , mValid(true)
    , pThread(new QThread())
    , pBuffer(new char[MAX_PACKET_SIZE])
{
    QObject::connect(pThread, &QThread::started,
                     this, &HTTPClientPrivate::init);

    this->moveToThread(pThread);
}

HTTPClientPrivate::~HTTPClientPrivate()
{
    if(pThread->isRunning())
    {
        pThread->quit();
        pThread->wait();
    }

    delete pThread;
    delete pBuffer;
    delete hn;
}

void HTTPClientPrivate::init()
{
    Q_Q(HTTPClient);
    mValid = false;
    emit q->enabled(mValid);
    emit q->message("Initialization...");

    // Инициализация
    if (WSAStartup (0x0101, &ws) != 0)
    {
        emit q->error(getError("WSAStartup"));
        this->cleanALL(0);
        return;
    }

    // Создаём сокет
    if (INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM,
                                      IPPROTO_TCP)))
    {
        emit q->error(getError("socket"));
        this->cleanALL(1);
        return;
    }

    mValid = true;
    emit q->enabled(mValid);
    emit q->message("Initialization completed");
    this->connectToHost();
}

void HTTPClientPrivate::getInfo()
{
    __print;
    Q_Q(HTTPClient);
    mValid = false;
    emit q->enabled(mValid);
    emit q->message("Loading...");

    QByteArray req = REQUEST(mCurrentPath.data(), mCurrentSite.data());
    if (SOCKET_ERROR == send(s, req.data(), req.size() + 1, 0))
    {
        emit q->error(getError("send"));
        this->cleanALL(1);
        return;
    }

    // Ждём ответа
    int len = 0;
    int res;

    fd_set read_s;
    timeval time_out;

    time_out.tv_sec = 0;
    time_out.tv_usec = 5000000; // 5 sec.

    mFullData.resize(0);
    do
    {
        FD_ZERO (&read_s);	 	// Обнуляем множество
        FD_SET(s, &read_s);
        FD_SET(s, &read_s); 	// Заносим в него наш сокет
        if (SOCKET_ERROR == (res = select(0, &read_s, NULL, NULL, &time_out)))
        {
            emit q->error(getError("select"));
            this->cleanALL(1);
            return;
        }
        if ((res != 0) && (FD_ISSET (s, &read_s)) )
        {
            // Данные готовы к чтению...
            if (SOCKET_ERROR == (len = recv(s, pBuffer, MAX_PACKET_SIZE, 0)))
            {
                emit q->error(getError("recv"));
                this->cleanALL(1);
                return;
            }
            mFullData.append(pBuffer, len);
        }
    }
    while (len > 0 && !pThread->isInterruptionRequested());

    emit q->data(mFullData);

    // Закрываем соединенеие
    if(SOCKET_ERROR == closesocket(s))
    {
        emit q->error(getError("closesocket"));
        this->cleanALL(0);
        return;
    }

    mValid = true;
    emit q->enabled(mValid);
    emit q->message((mFullData.isEmpty())
                    ? "Loading failure"
                    : "Loading completed");

    WSACleanup();

    pThread->exit();
}

void HTTPClientPrivate::connectToHost()
{
    Q_Q(HTTPClient);
    emit q->message("Connection to host...");
    mValid = false;

    // Получаем адрес
    if (NULL == (hn = gethostbyname((const char*)mCurrentSite.data())))
    {
        emit q->error(getError("gethostbyname"));
        this->cleanALL(1);
        return;
    }

    // Заполняем  поля структуры adr для использование ее в
    // connect
    adr.sin_family = AF_INET;
    adr.sin_addr.S_un.S_addr = *(DWORD* ) hn->h_addr_list[0];
    adr.sin_port = htons (80);

    // Устанавливаем соединение с сервером
    if (SOCKET_ERROR == ::connect(s, (sockaddr*) &adr, sizeof(adr)))
    {
        emit q->error(getError("connect"));
        this->cleanALL(1);
        return;
    }

    // Устанавливаем nonblocked mode
    BOOL l = TRUE;
    if (SOCKET_ERROR == ioctlsocket(s, FIONBIO, (unsigned long*)&l))
    {
        emit q->error(getError("ioctlsocket"));
        this->cleanALL(1);
        return;
    }

    mValid = true;
    emit q->message("Connection to host completed");

    this->getInfo();
}

QByteArray HTTPClientPrivate::getError(const char* function_name)
{
    int res = WSAGetLastError();
    return QByteArray("\nERROR: \tFunction \"" +
                      QByteArray(function_name) +
                      "\" call failed,\n\tWSAGetLastError() return error code: dec = ["
                      + QByteArray::number(res) + "]\n");
}

void HTTPClientPrivate::cleanALL(int level)
{
    switch(level)
    {
    case 1:
        closesocket(s);
    case 0:
        WSACleanup();
        pThread->exit();
    }
}

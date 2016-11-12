#include <QDebug>
#include <QByteArray>

#include "httpclient.h"
#include "httpclient_p.h"

// Необходимые макро-определения
#define request "GET /enp/rfc/rfc768.txt HTTP/1.0\r\nHost: " \
    "www.networksorcery.com\r\n\r\n" 	// HTML запрос.

#define MAX_PACKET_SIZE 1024

#define REQUEST(arg1, arg2) QByteArray(\
    QString("GET %1 HTTP/1.0\r\nHost: \
    %2\r\n\r\n").arg(arg1, arg2).toUtf8()).data()


HTTPClient::HTTPClient(QObject *parent)
    : QObject(parent)
    , d_ptr(new HTTPClientPrivate(parent))
{
    Q_D(HTTPClient);
    d->q_ptr = this;

    __print << "\n" << request;
    __print << "\n" << REQUEST("/enp/rfc/rfc768.txt", "www.networksorcery.com");
}

HTTPClient::~HTTPClient()
{
    d_ptr->deleteLater();
}

void HTTPClient::SDELAT_WSE()
{
    Q_D(HTTPClient);
    d->init();
    __print << d->mValid;

    if(!d->mValid)
        return;

//    d->connectToHost("www.vk.com");
    __print << d->mValid;

    if(!d->mValid)
        return;

//    d->getInfo();
    __print <<d->mValid;
}

void HTTPClient::init()
{
    Q_D(HTTPClient);
    if(!d->pThread->isRunning())
        d->pThread->start();
}

bool HTTPClient::isValid()
{
    Q_D(HTTPClient);
    return d->mValid;
}

void HTTPClient::getData(QByteArray link)
{
    Q_D(HTTPClient);
    int index = link.indexOf("/");
    QByteArray site;
    QByteArray path;

    site.resize(index);
    path.resize(link.size() - index);

    qCopy(link.begin(), link.begin() + index, site.begin());
    qCopy(link.begin() + index, link.end(), path.begin());

    d->connectToHost(site);

    if(!this->isValid())
    {
        emit message("Connection failure");
        return;
    }

    d->getInfo(site, path);
}

HTTPClientPrivate::HTTPClientPrivate(QObject *parent)
    : QObject(parent)
    , mValid(false)
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
    // Инициализация
    if (WSAStartup (0x0101, &ws) != 0)
    {
        emit q->data(getError("WSAStartup"));
        return;
    }

    // Создаём сокет
    if (INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM,
                          IPPROTO_TCP)))
    {
        emit q->data(getError("socket"));
        return;
    }

    mValid = true;
}

void HTTPClientPrivate::getInfo(QByteArray site, QByteArray path)
{
    Q_Q(HTTPClient);
    __print;
    mValid = false;

    if (SOCKET_ERROR == send(s, (const char*)REQUEST(path.data(), site.data()),
                             sizeof(REQUEST(path.data(), site.data())), 0))
    {
        emit q->data(getError("send"));
        return;
    }

    // Ждём ответа
    int len;
    int res;

    fd_set read_s;
    timeval time_out;

    time_out.tv_sec = 0;
    time_out.tv_usec = 500000; // 0.5 sec.

    mFullData.resize(0);
    do
    {
        FD_ZERO (&read_s);	 	// Обнуляем множество
        FD_SET (s, &read_s); 	// Заносим в него наш сокет
        if (SOCKET_ERROR == (res = select (0, &read_s, NULL, NULL, &time_out)))
        {
            emit q->data(getError("select"));
            return;
        }

        if ((res!=0) && (FD_ISSET (s, &read_s)) )
        {
            // Данные готовы к чтению...
            if (SOCKET_ERROR == (len = recv(s, pBuffer, MAX_PACKET_SIZE, 0)))
            {
                emit q->data(getError("recv"));
                return;
            }
            __print << len;
            mFullData.append(pBuffer, len);
        }
    }
    while (len!=0);


    __print << mFullData.data();
    emit q->data(mFullData);

    // Закрываем соединенеие
    if (SOCKET_ERROR == closesocket (s) )
    {
        emit q->data(getError("closesocket"));
        return;
    }

    mValid = true;
}

void HTTPClientPrivate::connectToHost(QByteArray host)
{
    Q_Q(HTTPClient);
    mValid = false;

    // Получаем адрес
    if (NULL == (hn = gethostbyname(host.data())))
    {
        emit q->data(getError("gethostbyname"));
        return;
    }

    // Заполняем  поля структуры adr для использование ее в
    // connect
    adr.sin_family = AF_INET;
    adr.sin_addr.S_un.S_addr = *(DWORD* ) hn->h_addr_list[0];
    adr.sin_port = htons (80);

    // Устанавливаем соединение с сервером
    if (SOCKET_ERROR == ::connect( s, (sockaddr*) &adr,
                        sizeof(adr) ) )
    {
        emit q->data(getError("connect"));
        return;
    }

    // Устанавливаем nonblocked mode
    BOOL l = TRUE;
    if (SOCKET_ERROR == ioctlsocket(s, FIONBIO, (unsigned long* ) &l))
    {
        emit q->data(getError("ioctlsocket"));
        return;
    }

    mValid = true;
}

QByteArray HTTPClientPrivate::getError(const char* function_name)
{
    int res = WSAGetLastError();
    return QByteArray("\nERROR: \tFunction \"" +
                      QByteArray(function_name) +
                      "\" call failed,\n\tWSAGetLastError() return error code: dec = ["
                      + QByteArray::number(res) + "]\n");
}


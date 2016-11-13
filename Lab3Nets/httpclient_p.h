#ifndef HTTPCLIENT_P
#define HTTPCLIENT_P

#include <QThread>
#include <QObject>

#include "winsock2.h"

class HTTPClient;

class HTTPClientPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(HTTPClient)

public:
    HTTPClientPrivate(QObject* parent = 0);
    virtual ~HTTPClientPrivate();

    bool mValid;
    QThread* pThread;
    HTTPClient* q_ptr;

    SOCKET s;
    WSADATA ws;
    hostent* hn;
    char* pBuffer;
    sockaddr_in	adr;
    QByteArray mFullData;
    QByteArray mCurrentSite;
    QByteArray mCurrentPath;

public slots:
    void init();
    void getInfo();
    void connectToHost();

private slots:
    void cleanALL(int level);
    QByteArray getError(const char* function_name);
};

#endif // HTTPCLIENT_P


#ifndef HTTPCLIENT
#define HTTPCLIENT

#include <QObject>

class HTTPClientPrivate;

class HTTPClient : public QObject
{
    Q_OBJECT

public:
    explicit HTTPClient(QObject* parent = 0);
    virtual ~HTTPClient();

    void SDELAT_WSE();

signals:
    void message(QString txt);
    void data(QByteArray data);

public slots:
    void init();
    bool isValid();

    void getData(QByteArray link);

private:
    Q_DECLARE_PRIVATE(HTTPClient)
    HTTPClientPrivate* d_ptr;
};

#endif // HTTPCLIENT


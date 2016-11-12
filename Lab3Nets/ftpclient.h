#ifndef FTPCLIENT
#define FTPCLIENT

#include <QObject>

class FTPClientPrivate;

class FTPClient : public QObject
{
    Q_OBJECT

public:
    FTPClient(QObject* parent = 0);
    virtual ~FTPClient();

private:
    Q_DECLARE_PRIVATE(FTPClient)
    FTPClientPrivate* d_ptr;
};

#endif // FTPCLIENT


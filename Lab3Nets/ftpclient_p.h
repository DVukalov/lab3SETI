#ifndef FTPCLIENT_P
#define FTPCLIENT_P

#include <QObject>

class FTPClient;

class FTPClientPrivate : public QObject
{
    Q_OBJECT
    Q_DECLARE_PUBLIC(FTPClient)

public:
    FTPClientPrivate(QObject* parent = 0);
    virtual ~FTPClientPrivate();

    FTPClient* q_ptr;
};

#endif // FTPCLIENT_P


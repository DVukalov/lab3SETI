#include "ftpclient.h"
#include "ftpclient_p.h"

FTPClient::FTPClient(QObject *parent)
    : QObject(parent)
    , d_ptr(new FTPClientPrivate(parent))
{
    Q_D(FTPClient);
    d->q_ptr = this;
}

FTPClient::~FTPClient()
{
    d_ptr->deleteLater();
}

FTPClientPrivate::FTPClientPrivate(QObject *parent)
    : QObject(parent)
{

}

FTPClientPrivate::~FTPClientPrivate()
{

}

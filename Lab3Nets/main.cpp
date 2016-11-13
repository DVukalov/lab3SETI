#include "interface.h"
#include "httpinterface.h"

#include <QObject>
#include <QApplication>
#include <ftpclient.h>

// ftp://ftp.mccme.ru/
//ftp://ftp.startrekftp.ru/
//http://www.shapovalov.org/publ/7-1-0-52

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;

    HTTPInterface h;
    FtpWindow f;

    QObject::connect(&w, SIGNAL(HTTP()), &h, SLOT(show()));
    QObject::connect(&w, SIGNAL(FTP()), &f, SLOT(show()));
    w.show();
    return a.exec();
}

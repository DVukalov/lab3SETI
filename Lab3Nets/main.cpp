#include "interface.h"
#include "httpclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;
    HTTPClient* h = new HTTPClient;
    h->SDELAT_WSE();
    w.show();

    return a.exec();
}

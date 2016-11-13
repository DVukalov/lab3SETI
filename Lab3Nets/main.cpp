#include "interface.h"
#include "httpinterface.h"

#include <QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Interface w;
    HTTPInterface h;

    QObject::connect(&w, SIGNAL(HTTP()), &h, SLOT(show()));
    w.show();

    return a.exec();
}

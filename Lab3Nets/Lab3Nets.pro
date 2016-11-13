#-------------------------------------------------
#
# Project created by QtCreator 2016-11-12T10:39:35
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lws2_32
LIBS += -liphlpapi

TARGET = Lab3Nets
TEMPLATE = app


SOURCES += main.cpp\
        interface.cpp \
    httpclient.cpp \
    ftpclient.cpp \
    httpinterface.cpp \
    qftp.cpp \
    qurlinfo.cpp

HEADERS  += interface.h \
    httpclient.h \
    httpclient_p.h \
    ftpclient.h \
    httpinterface.h \
    qftp.h \
    qurlinfo.h

FORMS    += interface.ui \
    httpinterface.ui

QMAKE_CXXFLAGS += -std=c++11

DEFINES += __print="\"qDebug()<<__FILE__<<__LINE__<<Q_FUNC_INFO\""

RESOURCES += \
    ftp.qrc

symbian {
    TARGET.UID3 = 0xA000A648
    include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
    INCLUDEPATH += $$APP_LAYER_SYSTEMINCLUDE
    TARGET.CAPABILITY="NetworkServices ReadUserData WriteUserData"
}
maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)
symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)

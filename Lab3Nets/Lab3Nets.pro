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
    ftpclient.cpp

HEADERS  += interface.h \
    httpclient.h \
    httpclient_p.h \
    ftpclient.h \
    ftpclient_p.h

FORMS    += interface.ui

QMAKE_CXXFLAGS += -std=c++11

DEFINES += __print="\"qDebug()<<__FILE__<<__LINE__<<Q_FUNC_INFO\""

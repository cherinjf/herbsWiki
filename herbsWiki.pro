#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T10:35:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = herbsWiki
TEMPLATE = app


SOURCES += main.cpp\
        connectdb.cpp

HEADERS  += connectdb.h

FORMS    += connectdb.ui

RESOURCES += \
    resources.qrc

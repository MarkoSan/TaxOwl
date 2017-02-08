#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T06:32:03
#
#-------------------------------------------------

QT       -= gui

TARGET = uePOSCommProtocol
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ueposcommprotocol.cpp

HEADERS += ueposcommprotocol.h \
    uecommands.h \
    uedefaults.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

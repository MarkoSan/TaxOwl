#-------------------------------------------------
#
# Project created by QtCreator 2016-07-25T12:40:37
#
#-------------------------------------------------

TARGET = ueSyntaxHiglighter
TEMPLATE = lib
CONFIG += staticlib
QT += widgets

SOURCES += uesyntaxhiglighter.cpp \
    uelogwindow.cpp

HEADERS += uesyntaxhiglighter.h \
    uehighlightrule.h \
    uelogwindow.h \
    uelogentrytype.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

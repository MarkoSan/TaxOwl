#-------------------------------------------------
#
# Project created by QtCreator 2016-07-25T12:40:37
#
#-------------------------------------------------

TARGET = ueSyntaxHighlighter
TEMPLATE = lib
CONFIG += staticlib
QT += widgets

SOURCES += uesyntaxhighlighter.cpp \
    uelogwindow.cpp

HEADERS += uesyntaxhighlighter.h \
    uehighlightrule.h \
    uelogwindow.h \
    uelogentrytype.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

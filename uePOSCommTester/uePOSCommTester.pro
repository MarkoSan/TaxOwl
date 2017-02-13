#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T08:07:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uePOSCommTester
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uecentralwidget.cpp \
    net/uedatatransfersocket.cpp \
    net/uenetworkdiscoverysocket.cpp \
    uecommandswidget.cpp \
    uecommandsdockwidget.cpp \
    database/models/uejsonplacestablemodel.cpp \
    gui/ueplacestableview.cpp \
    gui/ueplacestabledialog.cpp \
    net/uedatareadertask.cpp

HEADERS  += mainwindow.h \
    uecentralwidget.h \
    net/uedatatransfersocket.h \
    net/uenetworkdiscoverysocket.h \
    uecommandswidget.h \
    uecommandsdockwidget.h \
    database/models/uejsonplacestablemodel.h \
    gui/ueplacestableview.h \
    gui/ueplacestabledialog.h \
    net/uedatareadertask.h

RESOURCES += \
    ueicons.qrc

INCLUDEPATH += "$$PWD/../uePOSCommProtocol"
DEPENDPATH += "$$PWD/../uePOSCommProtocol"
LIBS += "$$PWD/../build/uePOSCommProtocol/x64/linux/debug/libuePOSCommProtocol.a"

INCLUDEPATH += "$$PWD/../ueSyntaxHighlighter"
DEPENDPATH += "$$PWD/../ueSyntaxHighlighter"
LIBS += "$$PWD/../build/ueSyntaxHighlighter/x64/linux/debug/libueSyntaxHighlighter.a"

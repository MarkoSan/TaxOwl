#-------------------------------------------------
#
# Project created by QtCreator 2016-06-24T09:06:56
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = uePOSCommServer
TEMPLATE = app


SOURCES += main.cpp\
        uemainwindow.cpp \
    gui/uecentralwidget.cpp \
    net/uetcpserver.cpp \
    net/uetask.cpp \
    gui/ueconnectedclientstableview.cpp \
    core/ueconnectedclientstablemodel.cpp \
    core/ueconnectedclientrecord.cpp \
    gui/ueconnectedclientstablewidget.cpp \
    settings/uesettings.cpp \
    gui/uedatabaseserversettingswindow.cpp \
    database/models/ueplacesmodel.cpp \
    net/ueclient.cpp

HEADERS  += uemainwindow.h \
    gui/uecentralwidget.h \
    net/uetcpserver.h \
    net/uetask.h \
    gui/ueconnectedclientstableview.h \
    core/ueconnectedclientstablemodel.h \
    core/ueconnectedclientrecord.h \
    gui/ueconnectedclientstablewidget.h \
    settings/uesettings.h \
    settings/uesettingsdefaults.h \
    gui/uedatabaseserversettingswindow.h \
    database/models/ueplacesmodel.h \
    database/models/uetypes.h \
    database/models/uefieldindexes.h \
    database/models/uequeries.h \
    net/ueclient.h

INCLUDEPATH += "$$PWD/../uePOSCommProtocol"
DEPENDPATH += "$$PWD/../uePOSCommProtocol"
LIBS += "$$PWD/../build/uePOSCommProtocol/x64/linux/debug/libuePOSCommProtocol.a"

INCLUDEPATH += "$$PWD/../ueSyntaxHighlighter"
DEPENDPATH += "$$PWD/../ueSyntaxHighlighter"
LIBS += "$$PWD/../build/ueSyntaxHighlighter/x64/linux/debug/libueSyntaxHighlighter.a"

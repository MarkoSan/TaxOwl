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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/release/ -luePOSCommProtocol
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/debug/ -luePOSCommProtocol
else:unix: LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/ -luePOSCommProtocol

INCLUDEPATH += $$PWD/../uePOSCommProtocol
DEPENDPATH += $$PWD/../uePOSCommProtocol

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/release/libuePOSCommProtocol.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/debug/libuePOSCommProtocol.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/release/uePOSCommProtocol.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/debug/uePOSCommProtocol.lib
else:unix: PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/libuePOSCommProtocol.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/release/ -lueSyntaxHiglighter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/ -lueSyntaxHiglighter
else:unix: LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/ -lueSyntaxHiglighter

INCLUDEPATH += $$PWD/../ueSyntaxHiglighter
DEPENDPATH += $$PWD/../ueSyntaxHiglighter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/release/libueSyntaxHiglighter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/libueSyntaxHiglighter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/release/ueSyntaxHiglighter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/ueSyntaxHiglighter.lib
else:unix: PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/libueSyntaxHiglighter.a

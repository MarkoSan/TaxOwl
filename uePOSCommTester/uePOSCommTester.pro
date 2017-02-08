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
    gui/ueplacestabledialog.cpp

HEADERS  += mainwindow.h \
    uecentralwidget.h \
    net/uedatatransfersocket.h \
    net/uenetworkdiscoverysocket.h \
    uecommandswidget.h \
    uecommandsdockwidget.h \
    database/models/uejsonplacestablemodel.h \
    gui/ueplacestableview.h \
    gui/ueplacestabledialog.h

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/release/ -luePOSCommProtocol
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/debug/ -luePOSCommProtocol
#else:unix: LIBS += -L$$PWD/../uePOSCommProtocol/build/x64/debug/ -luePOSCommProtocol

#INCLUDEPATH += $$PWD/../uePOSCommProtocol
#DEPENDPATH += $$PWD/../uePOSCommProtocol

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/release/libuePOSCommProtocol.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/debug/libuePOSCommProtocol.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/release/uePOSCommProtocol.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/debug/uePOSCommProtocol.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../uePOSCommProtocol/build/x64/debug/libuePOSCommProtocol.a

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/release/ -lueSyntaxHiglighter
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/ -lueSyntaxHiglighter
#else:unix: LIBS += -L$$PWD/../ueSyntaxHiglighter/build/x64/debug/ -lueSyntaxHiglighter

#INCLUDEPATH += $$PWD/../ueSyntaxHiglighter
#DEPENDPATH += $$PWD/../ueSyntaxHiglighter

#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/release/libueSyntaxHiglighter.a
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/libueSyntaxHiglighter.a
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/release/ueSyntaxHiglighter.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/debug/ueSyntaxHiglighter.lib
#else:unix: PRE_TARGETDEPS += $$PWD/../ueSyntaxHiglighter/build/x64/debug/libueSyntaxHiglighter.a

RESOURCES += \
    ueicons.qrc

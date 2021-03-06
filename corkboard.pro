#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T17:00:24
#
#-------------------------------------------------

QT      += core gui widgets

CONFIG  += c++11

TARGET = corkboard
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        corkboard.cpp \
        corkboardscene.cpp \
    notepackitem.cpp \
    note.cpp \
    noteproxywidget.cpp

HEADERS += mainwindow.h \
        corkboard.h \
        corkboardscene.h \
    notepackitem.h \
    note.h \
    noteproxywidget.h

FORMS    +=

RESOURCES += \
    resources.qrc

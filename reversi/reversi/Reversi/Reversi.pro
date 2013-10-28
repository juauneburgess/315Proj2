#-------------------------------------------------
#
# Project created by QtCreator 2013-10-25T22:26:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Reversi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    ai.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    ai.h

FORMS    += mainwindow.ui

RESOURCES += \
    Pics.qrc

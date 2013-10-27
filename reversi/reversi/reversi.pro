#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T00:06:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = reversi
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
    myResources.qrc

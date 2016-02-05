#-------------------------------------------------
#
# Project created by QtCreator 2016-02-04T15:51:16
#
#-------------------------------------------------

QT       += core gui network

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuiServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    clientthread.cpp

HEADERS  += mainwindow.h \
    server.h \
    clientthread.h

FORMS    += mainwindow.ui

#-------------------------------------------------
#
# Project created by QtCreator 2013-12-15T18:09:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IndieLibEditor
TEMPLATE = app

DEPENDPATH += . tinyxml
INCLUDEPATH += . tinyxml

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/elementpanel.cpp \
    src/hierarchypanel.cpp

HEADERS  += src/mainwindow.h \
    src/elementpanel.h \
    src/hierarchypanel.h

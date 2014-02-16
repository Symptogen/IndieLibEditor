#-------------------------------------------------
#
# Project created by QtCreator 2013-12-15T18:09:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IndieLibEditor
TEMPLATE = app

SOURCES += src/main.cpp\
        src/widgets/mainwindow.cpp \
    src/widgets/elementpanel.cpp \
    src/widgets/hierarchypanel.cpp \
    src/project.cpp \
    src/dialogs/newprojectdialog.cpp \
    src/graphic/scene.cpp \
    src/command/movecommand.cpp \
    src/command/invoker.cpp \
    src/command/opacitycommand.cpp \
    src/widgets/entityelementpanel.cpp \
    src/iomodule.cpp \
    src/graphic/graphicalitem.cpp

HEADERS  += src/widgets/mainwindow.h \
    src/widgets/elementpanel.h \
    src/widgets/hierarchypanel.h \
    src/project.h \
    src/level.h \
    src/dialogs/newprojectdialog.h \
    src/graphic/scene.h \
    src/command/movecommand.h \
    src/command/invoker.h \
    src/command/opacitycommand.h \
    src/widgets/entityelementpanel.h \
    src/iomodule.h \
    src/graphic/graphicalitem.h

#-------------------------------------------------
#
# Project created by QtCreator 2013-12-15T18:09:36
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IndieLibEditor
TEMPLATE = app

SOURCES += src/main.cpp\
        src/widgets/mainwindow.cpp \
    src/widgets/hierarchypanel.cpp \
    src/project.cpp \
    src/application.cpp \
    src/dialogs/newprojectdialog.cpp \
    src/graphic/scene.cpp \
    src/command/movecommand.cpp \
    src/command/invoker.cpp \
    src/command/opacitycommand.cpp \
    src/iomodule.cpp \
    src/graphic/graphicalitem.cpp \
    src/widgets/resourcesbrowserwidget.cpp \
    src/widgets/panelwidget.cpp \
    src/entitymanager.cpp \
    src/widgets/entitywidget.cpp

HEADERS  += src/widgets/mainwindow.h \
    src/widgets/hierarchypanel.h \
    src/project.h \
    src/application.h \
    src/level.h \
    src/dialogs/newprojectdialog.h \
    src/graphic/scene.h \
    src/command/movecommand.h \
    src/command/invoker.h \
    src/command/opacitycommand.h \
    src/iomodule.h \
    src/graphic/graphicalitem.h \
    src/widgets/resourcesbrowserwidget.h \
    src/widgets/panelwidget.h \
    src/singleton.h \
    src/entitymanager.h \
    src/widgets/entitywidget.h

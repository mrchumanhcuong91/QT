#-------------------------------------------------
#
# Project created by QtCreator 2016-04-15T11:18:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = library
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    user.cpp \
    admin.cpp \
    books.cpp

HEADERS  += mainwindow.h \
    person.h \
    user.h \
    admin.h \
    books.h

FORMS    += mainwindow.ui

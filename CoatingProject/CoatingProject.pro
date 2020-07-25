TEMPLATE = app
TARGET = CoatingProject

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network

SOURCES += \
    main.cpp \
    window.cpp \
    weather.cpp

HEADERS += \
    window.h \
    weather.h

DISTFILES += \
    ../Pictures/crocodile.jpg

QMAKE_CXXFLAGS += -std=c++0x


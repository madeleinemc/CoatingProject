TEMPLATE = app
TARGET = helloworld

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h

DISTFILES += \
    ../Pictures/crocodile.jpg

QMAKE_CXXFLAGS += -std=c++0x


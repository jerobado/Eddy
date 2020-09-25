TEMPLATE = app

QT = core gui widgets

HEADERS = include/window.h

SOURCES = src/main.cpp  \
          src/window.cpp

INCLUDEPATH = include

TARGET = eddy

target.path = /opt/Eddy
target.files = eddy
INSTALLS += target
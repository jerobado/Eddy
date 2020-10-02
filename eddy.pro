TEMPLATE = app

QT = core gui widgets

HEADERS = include/window.h

SOURCES = src/main.cpp  \
          src/window.cpp

INCLUDEPATH = include

TARGET = eddy

# executable file
target.path = /opt/Eddy
target.files = eddy

# image files
images.path = /opt/Eddy/images
images.files = images/*

# extra files
extra.path = /opt/Eddy
extra.files = eddy.desktop

# copy eddy.desktop to /usr/share/applications
desktopfile.path = /usr/share/applications
desktopfile.files = /opt/Eddy/eddy.desktop
desktopfile.commands = cp -f /opt/Eddy/eddy.desktop /usr/share/applications

INSTALLS += target images extra desktopfile

QMAKE_LFLAGS = -no-pie
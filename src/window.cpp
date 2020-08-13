#include "window.h"

Window::Window(QMainWindow *parent) : QMainWindow(parent)
{
    // widgets
    eddyPlainTextEdit = new QPlainTextEdit();


    // properties
    resize(250, 250);
    setWindowTitle("Eddy 0.1");

    // layouts
    setCentralWidget(eddyPlainTextEdit);

    // connections
}
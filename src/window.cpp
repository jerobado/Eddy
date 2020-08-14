#include "window.h"

Window::Window(QMainWindow *parent) : QMainWindow(parent)
{
    // widgets
    eddyPlainTextEdit = new QPlainTextEdit();


    // properties
    resize(500, 750);
    setWindowTitle("Eddy 0.1");

    // layouts
    setCentralWidget(eddyPlainTextEdit);

    // connections
}
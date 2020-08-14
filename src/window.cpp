#include "window.h"

Window::Window(QMainWindow *parent) : QMainWindow(parent)
{
    // widgets
    eddyPlainTextEdit = new QPlainTextEdit();
    

    // actions and menus
    createActions();
    createMenus();


    // properties
    resize(500, 750);
    setWindowTitle("Eddy 0.1");

    // layouts
    setCentralWidget(eddyPlainTextEdit);

    // connections
}

void Window::createActions()
{
    newAction = new QAction(tr("&New"), this);
    quitAction = new QAction(tr("&Quit"), this);
    // [] TODO: set signal and slots
}


void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(quitAction);
}

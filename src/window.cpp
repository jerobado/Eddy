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
    setWindowTitle("Eddy 0.1.1");

    // layouts
    setCentralWidget(eddyPlainTextEdit);

    // connections
    connect(saveAsAction, &QAction::triggered,
            this, &Window::saveAs);

    connect(quitAction, &QAction::triggered, 
            this, &Window::exit);
}

void Window::createActions()
{
    newAction = new QAction(tr("&New"), this);
    saveAsAction = new QAction(tr("Save &As"), this);
    quitAction = new QAction(tr("&Quit"), this);
    // [] TODO: set signal and slots
}


void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);
}

void Window::saveAs()
{
    // [] TODO: learn how to use QFile and QTextStream 
    qDebug() << eddyPlainTextEdit->toPlainText();
}


void Window::exit()
{
    QCoreApplication::quit();
}

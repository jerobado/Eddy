#include "window.h"


Window::Window(QMainWindow *parent) : QMainWindow(parent)
{
    createWidgets();   
    createActions();
    createMenus();
    setProperties();
    setLayouts();
    setConnections();
 }


void Window::createWidgets()
{
    eddyPlainTextEdit = new QPlainTextEdit();
}


void Window::createActions()
{
    newAction = new QAction(tr("&New"), this);
    saveAsAction = new QAction(tr("Save &As"), this);
    quitAction = new QAction(tr("&Quit"), this);
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


void Window::setProperties()
{
    resize(500, 750);
    setWindowTitle("Eddy 0.1.2");
}


void Window::setLayouts()
{
    setCentralWidget(eddyPlainTextEdit);
}


void Window::setConnections()
{
    connect(saveAsAction, &QAction::triggered,
            this, &Window::saveAs);
    connect(quitAction, &QAction::triggered, 
            this, &Window::exit);
}


void Window::saveAs()
{  
    QString filename = QFileDialog::getSaveFileName(this, 
                                                    tr("Save As"),
                                                    "untitled.txt",
                                                    tr("Text files (*.txt)"));
    QFile file(filename);
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream writer(&file);
        writer << eddyPlainTextEdit->toPlainText();
    }
}


void Window::exit()
{
    QCoreApplication::quit();
}

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
    openAction = new QAction(tr("&Open"), this);
    saveAsAction = new QAction(tr("Save &As"), this);
    quitAction = new QAction(tr("&Quit"), this);
}


void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);
}


void Window::setProperties()
{
    resize(500, 750);
    setWindowTitle("Eddy 0.1.4");
}


void Window::setLayouts()
{
    setCentralWidget(eddyPlainTextEdit);
}


void Window::setConnections()
{
    connect(openAction, &QAction::triggered,
            this, &Window::open);
    connect(saveAsAction, &QAction::triggered,
            this, &Window::saveAs);
    connect(quitAction, &QAction::triggered, 
            this, &Window::exit);
}


// private slots here
void Window::open()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    ".",
                                                    tr("Text files (*.txt)"));
    QFile file(filename);
    if (file.open(QFile::ReadWrite))
    {
        QByteArray file_content = file.readAll();
        QString plaintext = QString::fromStdString(file_content.toStdString());
        eddyPlainTextEdit->setPlainText(plaintext);
    }
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

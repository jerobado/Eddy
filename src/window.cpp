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
    saveAction = new QAction(tr("&Save"), this);
    saveAsAction = new QAction(tr("Save &As"), this);
    quitAction = new QAction(tr("&Quit"), this);
}


void Window::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);
}


void Window::setProperties()
{
    resize(500, 750);
    setWindowTitle("Eddy 0.1.5");
}


void Window::setLayouts()
{
    setCentralWidget(eddyPlainTextEdit);
}


void Window::setConnections()
{
    connect(newAction, &QAction::triggered,
            this, &Window::newFile);
    connect(openAction, &QAction::triggered,
            this, &Window::open);
    connect(saveAction, &QAction::triggered,
            this, &Window::save);
    connect(saveAsAction, &QAction::triggered,
            this, &Window::saveAs);
    connect(quitAction, &QAction::triggered, 
            this, &Window::quit);
    connect(eddyPlainTextEdit, &QPlainTextEdit::textChanged,
            this, &Window::on_eddyPlainTextEdit_textChanged);
}


// private slots here
void Window::newFile()
{
    eddyPlainTextEdit->clear();
}


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


void Window::save()
{
    if (isEddyPlainTextEditTextChanged)
    {
        QFile file("sample.txt");   // [] TODO: get global working filename
        if (file.open(QFile::WriteOnly | QFile::Truncate))
        {
            QTextStream writer(&file);
            writer << eddyPlainTextEdit->toPlainText();
        }
        isEddyPlainTextEditTextChanged = false;
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


void Window::quit()
{
    QCoreApplication::quit();
}


void Window::on_eddyPlainTextEdit_textChanged()
{
    isEddyPlainTextEditTextChanged = true;
}
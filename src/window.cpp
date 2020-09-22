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
    newAction->setShortcut(QKeySequence::New);
    openAction->setShortcut(QKeySequence::Open);
    saveAction->setShortcut(QKeySequence::Save);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    quitAction->setShortcut(QKeySequence::Quit);
    resize(500, 750);
    setWindowTitle(appName + " " + appVersion);
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
    workingFilename = "";
    isNewFile = true;
    eddyPlainTextEdit->clear();
    setWindowTitle(appName + " " + appVersion);
}


void Window::open()
{  
    workingFilename = QFileDialog::getOpenFileName(this,
                                                   tr("Open File"),
                                                   lastKnownFilePath,
                                                   tr("Text files (*.txt);;Any files (*)"));

    QFile file(workingFilename);
    QFileInfo fileinfo(workingFilename);
    if (file.open(QFile::ReadWrite))
    {

        QByteArray file_content = file.readAll();
        QString plaintext = QString::fromStdString(file_content.toStdString());
        eddyPlainTextEdit->setPlainText(plaintext);
        isNewFile = false;
        lastKnownFilePath = fileinfo.absolutePath();
        setWindowTitle(fileinfo.fileName() + " - " + appName + " " + appVersion);
    }
}


void Window::save()
{
    if (isEddyPlainTextEditTextChanged)
    {
        QFile file(workingFilename);
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
    workingFilename = QFileDialog::getSaveFileName(this, 
                                                   tr("Save As"),
                                                   lastKnownFilePath + "/untitled.txt",
                                                   tr("Text files (*.txt)"));
    QFile file(workingFilename);
    QFileInfo fileinfo(workingFilename);
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream writer(&file);
        writer << eddyPlainTextEdit->toPlainText();
        isNewFile = false;
        lastKnownFilePath = fileinfo.absolutePath();
        setWindowTitle(fileinfo.fileName() + " - " + appName + " " + appVersion);
    }
}


void Window::quit()
{
    QCoreApplication::quit();
}


void Window::on_eddyPlainTextEdit_textChanged()
{
    if (!isNewFile)
    {
        isEddyPlainTextEditTextChanged = true;
        save();
    }
}

// events
void Window::closeEvent(QCloseEvent *event)
{
    // [] TODO: call saveSettings()
    qDebug() << "closed";
}


void Window::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F5)
    {
        eddyPlainTextEdit->insertPlainText(QDateTime::currentDateTime().toString("h:m:ss ap, ddd, d MMM yyyy"));
    }
}

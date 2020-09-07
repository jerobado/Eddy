#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QByteArray>


class Window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Window(QMainWindow *parent=0);
    
    private:
        bool isEddyPlainTextEditTextChanged = false;
        QAction *newAction;
        QAction *openAction;
        QAction *saveAction;
        QAction *saveAsAction;
        QAction *quitAction;
        QMenu *fileMenu;
        QPlainTextEdit *eddyPlainTextEdit;
        void createWidgets();
        void createActions();
        void createMenus();
        void setProperties();
        void setLayouts();
        void setConnections();

    private slots:
        void newFile();
        void open();
        void save();
        void saveAs();
        void quit();
        void on_eddyPlainTextEdit_textChanged();

};

#endif // WINDOW_H


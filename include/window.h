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


class Window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Window(QMainWindow *parent=0);
    
    private:
        QAction *newAction;
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
        void saveAs();
        void exit();

};

#endif // WINDOW_H


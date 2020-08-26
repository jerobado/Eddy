#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPlainTextEdit>
#include <QCoreApplication>

#include <QDebug>


class Window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Window(QMainWindow *parent=0);
    
    private:
        QAction *newAction;
        QAction *quitAction;
        QMenu *fileMenu;
        QPlainTextEdit *eddyPlainTextEdit;
        void createActions();
        void createMenus();

    private slots:
        void exit();

};

#endif // WINDOW_H


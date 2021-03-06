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
#include <QFileInfo>
#include <QKeySequence>
#include <QDateTime>
#include <QSettings>
#include <QIcon>
#include <QStringBuilder>


class Window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Window(QMainWindow *parent=0);
        bool isEddyPlainTextEditTextChanged;
        bool isNewFile;
        QString appName;
        QString appVersion;
        QString workingFilename;
        QString lastKnownFilePath;
        QString timestampFormat;    

    private:
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
        void readSettings();
        void saveSettings();

    protected:
        void closeEvent(QCloseEvent *event);
        void keyPressEvent(QKeyEvent *event);

    private slots:
        void newFile();
        void open();
        void save();
        void saveAs();
        void quit();
        void on_eddyPlainTextEdit_textChanged();

};

#endif // WINDOW_H


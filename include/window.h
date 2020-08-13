#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

class QPushButton;
class PlainQTextEdit;

class Window : public QMainWindow
{
    Q_OBJECT
    public:
        explicit Window(QMainWindow *parent=0);
    private:
        QPlainTextEdit *eddyPlainTextEdit;
};

#endif // WINDOW_H


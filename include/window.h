#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent=0);
};

#endif // WINDOW_H


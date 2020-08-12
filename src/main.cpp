#include <QApplication>
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Window eddyWindow;
    eddyWindow.show();

    return app.exec();
}

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include "window.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    Window window;

    // events to be processed
    window.show();

    //launch event loop
    return app.exec();
}

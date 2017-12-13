#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QFont defaultFont("Arial", 18);
    application.setFont(defaultFont);

    MainWindow window;
    window.show();

    return application.exec();
}

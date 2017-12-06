#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStackedWidget"
#include "QDesktopWidget"

#include "welcomeview.h"
#include "loginview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void setView(int index);

public:
    MainWindow();
    ~MainWindow();

    QStackedWidget* stack;
};

#endif // MAINWINDOW_H

#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class Welcome_View : public QWidget
{
    Q_OBJECT

signals:
    void loginPatientButton_Event();
    void loginDoctorButton_Event();
    void registerPatientButton_Event();
    void registerDoctorButton_Event();
    void exitButton_Event();

public:
    Welcome_View(QWidget* parent = 0);
    virtual ~Welcome_View() {}
};

#endif // WELCOMEVIEW_H

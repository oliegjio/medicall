#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class WelcomeView : public QWidget
{
    Q_OBJECT

signals:
    void loginPatientButton_Event();
    void loginDoctorButton_Event();
    void registerPatientButton_Event();
    void registerDoctorButton_Event();
    void exitButton_Event();

public:
    WelcomeView(QWidget* parent = 0);
    virtual ~WelcomeView() {}
};

#endif // WELCOMEVIEW_H

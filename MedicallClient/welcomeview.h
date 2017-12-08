#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class WelcomeView : public QWidget
{
    Q_OBJECT

private slots:
    void loginButton_Clicked();
    void registerPatientButton_Clicked();
    void registerDoctorButton_Clicked();

signals:
    void loginButton_Event();
    void registerPatientButton_Event();
    void registerDoctorButton_Event();

public:
    WelcomeView(QWidget* parent = 0);
    virtual ~WelcomeView() {}
};

#endif // WELCOMEVIEW_H

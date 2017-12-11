#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class Welcome_View : public QWidget
{
    Q_OBJECT

signals:
    void patientLoginButton_Clicked();
    void doctorLoginButton_Clicked();

    void patientRegisterButton_Clicked();
    void doctorRegisterButton_Clicked();

    void exitButton_Clicked();

public:
    Welcome_View(QWidget* parent = 0);
    virtual ~Welcome_View() {}
};

#endif // WELCOMEVIEW_H

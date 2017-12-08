#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class WelcomeView : public QWidget
{
    Q_OBJECT

private slots:
    void loginButtonClicked();
    void registerButtonClicked();

signals:
    void switchToLoginView();
    void switchToRegistrationView();

public:
    WelcomeView(QWidget* parent = 0);
    virtual ~WelcomeView() {}
};

#endif // WELCOMEVIEW_H

#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QLineEdit"
#include "QPushButton"
#include "QNetworkRequest"
#include "QNetworkReply"
#include "QHttpPart"

#include "networkmanager.h"

class LoginView : public QWidget
{
    Q_OBJECT

private slots:
    void loginClicked();
    void backClicked();

signals:
    void switchToLoginView();
    void switchToWelcomeView();

public:
    LoginView(QWidget* parent = 0);
    ~LoginView();

private:
    NetworkManager* network;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINVIEW_H

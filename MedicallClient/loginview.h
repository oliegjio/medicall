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
    void switchView(int index);

public:
    LoginView();
    ~LoginView();

private:
    NetworkManager* network;
    QLineEdit* username;
    QLineEdit* password;
};

#endif // LOGINVIEW_H

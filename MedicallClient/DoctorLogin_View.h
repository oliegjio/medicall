#ifndef LOGINDOCTORVIEW_H
#define LOGINDOCTORVIEW_H

#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "NetworkManager.h"

class DoctorLogin_VIew : public QWidget
{
    Q_OBJECT

private slots:
    void login_Finished(QNetworkReply* reply);
    void loginButton_Clicked();

signals:
    void switchToLoginView();
    void backButton_Event();
    void loggedIn(QVariantHash& data);

public:
    DoctorLogin_VIew(QWidget* parent = 0);
    ~DoctorLogin_VIew();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINDOCTORVIEW_H

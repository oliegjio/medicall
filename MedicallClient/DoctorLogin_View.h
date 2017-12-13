#ifndef LOGINDOCTORVIEW_H
#define LOGINDOCTORVIEW_H

#include <QVBoxLayout>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "NetworkManager.h"
#include "Button.h"
#include "LineEdit.h"
#include "Label.h"

class DoctorLogin_VIew : public QWidget
{
    Q_OBJECT

private slots:
    void login_Finished(QNetworkReply* reply);
    void loginButton_Clicked();

signals:
    void backButton_Clicked();
    void loggedIn_Event(QVariantHash& data);

public:
    DoctorLogin_VIew(QWidget* parent = 0);
    ~DoctorLogin_VIew();

private:
    QNetworkAccessManager* login_NetworkManager;
    LineEdit* username_Line;
    LineEdit* password_Line;
};

#endif // LOGINDOCTORVIEW_H

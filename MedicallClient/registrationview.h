#ifndef REGISTRATIONVIEW_H
#define REGISTRATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QDoubleValidator>
#include <QPushButton>

#include "networkmanager.h"

class RegistrationView : public QWidget
{
    Q_OBJECT

public:
    RegistrationView(QWidget* parent = 0);
    ~RegistrationView();

private:
    NetworkManager* network;
};

#endif // REGISTRATIONVIEW_H

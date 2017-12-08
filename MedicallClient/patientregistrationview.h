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

class PatientRegistrationView : public QWidget
{
    Q_OBJECT

public:
    PatientRegistrationView(QWidget* parent = 0);
    ~PatientRegistrationView();
};

#endif // REGISTRATIONVIEW_H

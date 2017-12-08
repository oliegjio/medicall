#ifndef PATIENTREGISTRATIONVIEW_H
#define PATIENTREGISTRATIONVIEW_H

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

signals:
    void backButton_Event();

private slots:
    void backButton_Clicked();
    void registerButton_Clicked();

public:
    PatientRegistrationView(QWidget* parent = 0);
    ~PatientRegistrationView();
};

#endif // PATIENTREGISTRATIONVIEW_H

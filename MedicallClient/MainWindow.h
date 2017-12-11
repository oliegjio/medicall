#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStackedWidget"
#include "QDesktopWidget"

#include "Welcome_View.h"
#include "PatientLogin_View.h"
#include "PatientRegistration_View.h"
#include "DoctorRegistration_View.h"
#include "Patient_View.h"
#include "Patient_Model.h"
#include "DoctorLogin_View.h"
#include "Doctor_Model.h"
#include "Doctor_View.h"
#include "Survey_View.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void switchToWelcomeView();
    void switchToLoginPatientView();
    void switchToLoginDoctorView();
    void switchToPatientRegistrationView();
    void switchToDoctorRegistrationView();
    void switchToSurveyView();
    void switchToPatientView(QVariantHash data);
    void switchToDoctorView(QVariantHash data);

private slots:
    void patientRegistration_Finished(QVariantHash data);
    void doctorRegistration_Finished(QVariantHash data);

public:
    MainWindow();
    ~MainWindow();

    QStackedWidget* stack;

private:
    Patient_View* patient_View;
    Doctor_View* doctor_View;
    Patient_Model* patient;
    Doctor_Model* doctor;
    Survey_View* survey_View;
};

#endif // MAINWINDOW_H

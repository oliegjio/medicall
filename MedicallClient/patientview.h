#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>

#include "patient.h"

class PatientView : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Event();

private slots:
    void backButton_Clicked();

public:
    PatientView(QWidget* parent = 0);
    ~PatientView();

    void init();
};

#endif // PATIENTVIEW_H

#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>

class PatientView : public QWidget
{
    Q_OBJECT

public:
    PatientView(QWidget* parent = 0);
    ~PatientView();
};

#endif // PATIENTVIEW_H

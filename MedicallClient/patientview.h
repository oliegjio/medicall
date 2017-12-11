#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QScrollArea>

#include "patient.h"
#include "recomendationwidget.h"

class PatientView : public QWidget
{
    Q_OBJECT

public slots:
    void getRecomendations_Finished(QNetworkReply* reply);

signals:
    void backButton_Event();

public:
    PatientView(QWidget* parent = 0);
    ~PatientView();

    void init();

private:
    QVBoxLayout* contentLayout;
};

#endif // PATIENTVIEW_H

#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QScrollArea>

#include "Patient_Model.h"
#include "Recomendation_Widget.h"

class Patient_View : public QWidget
{
    Q_OBJECT

public slots:
    void getRecomendations_Finished(QNetworkReply* reply);

signals:
    void backButton_Event();
    void takeSurveyButton_Event();

public:
    Patient_View(QWidget* parent = 0);
    ~Patient_View();

    void init();

private:
    QVBoxLayout* contentLayout;
};

#endif // PATIENTVIEW_H

#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QScrollArea>

#include "doctor.h"
#include "recomendationwidget.h"

class DoctorView : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Event();

private slots:
    void backButton_Clicked();

public:
    DoctorView(QWidget* parent = 0);
    ~DoctorView();

    void init();
};

#endif // DOCTORVIEW_H

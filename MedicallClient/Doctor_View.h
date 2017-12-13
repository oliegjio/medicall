#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QScrollArea>

#include "Doctor_Model.h"
#include "Recomendation_Widget.h"
#include "Button.h"
#include "Label.h"

class Doctor_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();

public:
    Doctor_View(QWidget* parent = 0);
    ~Doctor_View();

    void init();
};

#endif // DOCTORVIEW_H

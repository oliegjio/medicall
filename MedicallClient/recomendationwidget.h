#ifndef RECOMENDATIONWIDGET_H
#define RECOMENDATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>

class RecomendationWidget : public QWidget
{
    Q_OBJECT

public:
    RecomendationWidget(QWidget* parent = 0);
    ~RecomendationWidget();
};

#endif // RECOMENDATIONWIDGET_H

#ifndef RECOMENDATIONWIDGET_H
#define RECOMENDATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QTextEdit>

class RecomendationWidget : public QWidget
{
    Q_OBJECT

public:
    RecomendationWidget(QString title,
                        QString date,
                        QString content,
                        QString doctor,
                        QString patient,
                        QWidget* parent = 0);
    ~RecomendationWidget();

    QString id;
    QString title;
    QString date;
    QString content;
    QString doctor;
    QString patient;
};

#endif // RECOMENDATIONWIDGET_H

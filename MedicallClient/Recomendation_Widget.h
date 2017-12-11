#ifndef RECOMENDATIONWIDGET_H
#define RECOMENDATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QTextEdit>

class Recomendation_Widget : public QWidget
{
    Q_OBJECT

public:
    Recomendation_Widget(QString title, QString date, QString content,
                        QString doctor, QString patient, QWidget* parent = 0);
    ~Recomendation_Widget();

    QString id;
    QString title;
    QString date;
    QString content;
    QString doctor;
    QString patient;
};

#endif // RECOMENDATIONWIDGET_H

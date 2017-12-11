#ifndef SURVEYVIEW_H
#define SURVEYVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPushButton>

#include <opencv2/opencv.hpp>

class Survey_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Event();

public:
    Survey_View(QWidget* parent = 0);

private:
    QImage image;
};

#endif // SURVEYVIEW_H

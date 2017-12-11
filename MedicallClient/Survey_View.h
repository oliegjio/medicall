#ifndef SURVEYVIEW_H
#define SURVEYVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QCameraInfo>
#include <QMessageBox>
#include <QCameraViewfinder>

#include <opencv2/opencv.hpp>

class Survey_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();

public:
    Survey_View(QWidget* parent = 0);
    void init();

private:
    QImage image;
    QCamera* camera;
};

#endif // SURVEYVIEW_H

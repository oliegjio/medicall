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
#include <QFile>

#include <opencv2/opencv.hpp>

#include "Modal.h"
#include "CameraFrameGrubber.h"

class Survey_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();

public:
    Survey_View(QWidget* parent = 0);
    ~Survey_View();
    void init();

private:
    QImage image;
<<<<<<< HEAD

private slots:
    void handleImage(QImage image);
=======
    QCamera* camera;
>>>>>>> f0e4004fa7584cbc243d7eb6f0b855e0628023da
};

#endif // SURVEYVIEW_H

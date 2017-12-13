#ifndef CAMERAPLAYER_H
#define CAMERAPLAYER_H

#include <QWidget>
#include <QCamera>
#include <QCameraInfo>

#include "Modal.h"
#include "CameraFrameGrubber.h"

class CameraPlayer : public QWidget
{
  Q_OBJECT

public:
    CameraPlayer();

    bool start();
    void stop();
    void frameToPng(QString filename);

    bool isActive = false;

private:
    virtual void paintEvent(QPaintEvent* event);

    CameraFrameGrabber* grabber;
    QImage image;
    QCamera* camera;
    QWidget* display;


private slots:
    void handleImage(QImage image);
};

#endif // CAMERAPLAYER_H

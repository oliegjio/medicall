#include "CameraPlayer.h"

CameraPlayer::CameraPlayer()
{
    grabber = new CameraFrameGrabber(this);
}

bool CameraPlayer::start()
{
    if (QCameraInfo::availableCameras().count() <= 0)
        return false;

    camera = new QCamera(QCamera::FrontFace);
    camera->setViewfinder(grabber);
    connect(grabber,
            SIGNAL(frameAvailable(QImage)),
            this,
            SLOT(handleImage(QImage)));
    camera->start();

    return true;
}

void CameraPlayer::stop()
{
    camera->stop();
}

void CameraPlayer::handleImage(QImage image)
{
    QString filename = "frame.jpg";
    QFile file(filename);

    update();

    if (file.exists()) return;

    image.save(filename, "jpg");
}

void CameraPlayer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    grabber->paint(&painter);
}

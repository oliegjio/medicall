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

void CameraPlayer::frameToJpg(QString filename)
{
    QFile::remove(filename);
    QFile file(filename);
    image.save(filename, "jpg");
}

void CameraPlayer::handleImage(QImage image)
{
    this->image = image;
    update();
}

void CameraPlayer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    grabber->paint(&painter);
}

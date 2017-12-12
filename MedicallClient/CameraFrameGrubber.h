#ifndef CAMERAFRAMEGRUBBER_H
#define CAMERAFRAMEGRUBBER_H

#include <QAbstractVideoSurface>
#include <QList>
#include <QVideoSurfaceFormat>
#include <QWidget>
#include <QPainter>

class CameraFrameGrabber : public QAbstractVideoSurface
{
    Q_OBJECT

public:
    CameraFrameGrabber(QWidget* widget, QObject* parent = 0);

    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const;
    bool present(const QVideoFrame& frame);
    bool isFormatSupported(const QVideoSurfaceFormat& format) const;
    bool start(const QVideoSurfaceFormat& format);
    void stop();
    QRect videoRect() const { return targetRect; }
    void updateVideoRect();
    void paint(QPainter* painter);

private:
    QWidget* widget;
    QImage::Format imageFormat;
    QRect targetRect;
    QSize imageSize;
    QRect sourceRect;
    QVideoFrame currentFrame;

signals:
    void frameAvailable(QImage frame);
};


#endif // CAMERAFRAMEGRUBBER_H

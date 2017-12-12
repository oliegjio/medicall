#include "Survey_View.h"

Survey_View::~Survey_View()
{
    QString filename = "frame.jpg";
    QFile::remove(filename);
}

Survey_View::Survey_View(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignCenter);

    display = new QWidget();
    display->setMinimumHeight(400);
    display->setMinimumHeight(400);
    base_Layout->addWidget(display);

    grabber = new CameraFrameGrabber(this);

//    cv::Mat inputImage = cv::imread("/home/archie/Wallpapers/toph.png");
//    if(!inputImage.empty()) cv::imshow("Display Image", inputImage);

//    QSize imageSize = size() * 15;

//    image = QImage((const unsigned char*)(inputImage.data),
//                          inputImage.cols,
//                          inputImage.rows,
//                          QImage::Format_RGB888)
//                          .rgbSwapped()
//                          .scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

//    QLabel* image_Label = new QLabel();
//    image_Label->setPixmap(QPixmap::fromImage(image));
//    image_Label->setAlignment(Qt::AlignCenter);
//    base_Layout->addWidget(image_Label);

    QHBoxLayout* buttons_Layout = new QHBoxLayout();
    base_Layout->addLayout(buttons_Layout);
    buttons_Layout->addStretch(1);

    if (QCameraInfo::availableCameras().count() <= 0)
        Modal::message("No available cameras found!");

    QCamera* camera = new QCamera(QCamera::FrontFace);
    camera->setViewfinder(grabber);
    connect(grabber,
            SIGNAL(frameAvailable(QImage)),
            this,
            SLOT(handleImage(QImage)));
    camera->start();

    // # Back Button:
    QPushButton* back_Button = new QPushButton("Назад");
    buttons_Layout->addWidget(back_Button);
    connect(back_Button,
            &QPushButton::clicked,
            [=] () { camera->stop();
                     emit backButton_Clicked(); });

    buttons_Layout->addStretch(1);

    setLayout(base_Layout);
}

void Survey_View::handleImage(QImage image)
{
    QString filename = "frame.jpg";
    QFile file(filename);

    update();

    if (file.exists()) return;

    image.save(filename, "jpg");
}

void Survey_View::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    grabber->paint(&painter);
}

//void Survey_View::init()
//{
//    camera->start();
//}

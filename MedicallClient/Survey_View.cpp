#include "Survey_View.h"

Survey_View::Survey_View(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignCenter);

    cv::Mat inputImage = cv::imread("/home/archie/Wallpapers/toph.png");
//    if(!inputImage.empty()) cv::imshow("Display Image", inputImage);

    QSize imageSize = size() * 15;

    image = QImage((const unsigned char*)(inputImage.data),
                          inputImage.cols,
                          inputImage.rows,
                          QImage::Format_RGB888)
                          .rgbSwapped()
                          .scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QLabel* image_Label = new QLabel();
    image_Label->setPixmap(QPixmap::fromImage(image));
    image_Label->setAlignment(Qt::AlignCenter);
    base_Layout->addWidget(image_Label);

    QHBoxLayout* buttons_Layout = new QHBoxLayout();
    base_Layout->addLayout(buttons_Layout);
    buttons_Layout->addStretch(1);

    // # Back Button:
    QPushButton* back_Button = new QPushButton("Назад");
    buttons_Layout->addWidget(back_Button);
    connect(back_Button,
            &QPushButton::clicked,
            [=] () { emit backButton_Clicked(); });

    buttons_Layout->addStretch(1);

    setLayout(base_Layout);
}

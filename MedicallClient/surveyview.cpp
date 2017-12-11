#include "surveyview.h"

SurveyView::SurveyView(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* baseLayout = new QVBoxLayout();
    baseLayout->setAlignment(Qt::AlignCenter);

    cv::Mat inputImage = cv::imread("/home/archie/Wallpapers/toph.png");
//    if(!inputImage.empty()) cv::imshow("Display Image", inputImage);

    QSize imageSize = size() * 15;

    image = QImage((const unsigned char*)(inputImage.data),
                          inputImage.cols,
                          inputImage.rows,
                          QImage::Format_RGB888)
                          .rgbSwapped()
                          .scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(QPixmap::fromImage(image));
    imageLabel->setAlignment(Qt::AlignCenter);
    baseLayout->addWidget(imageLabel);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    baseLayout->addLayout(buttonsLayout);
    buttonsLayout->addStretch(1);

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    buttonsLayout->addWidget(backButton);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Event(); });

    buttonsLayout->addStretch(1);

    setLayout(baseLayout);
}

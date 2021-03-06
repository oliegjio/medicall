#ifndef FACEANALYZER_H
#define FACEANALYZER_H

#include <QObject>
#include <QDebug>
#include <QTemporaryDir>

#include <opencv2/opencv.hpp>
#include <iostream>

class FaceAnalyzer : public QObject
{
    Q_OBJECT

public:
    FaceAnalyzer(char* filename);

private:
    const int COLOR_MIN = 20;
    const int COLOR_MAX = 80;
    const int COLOR_SATURATION = 21;

    // Get coordinate region of cutted face
    IplImage *cutFace(IplImage* image, CvRect faceArea);

    cv::Mat deleteBackground(cv::Mat image);

    void combine(cv::Mat* original, cv::Mat mask);
};

#endif // FACEANALYZER_H

#include "FaceAnalyzer.h"

FaceAnalyzer::FaceAnalyzer(char* filename) : QObject()
{
    cv::Mat image = cv::imread(filename);

    cv::Mat gray;

    cvtColor(image, gray, cv::COLOR_BGR2GRAY); // Translate to black and white
    cv::CascadeClassifier cascadeSymbol; // Cascade definition

    // Load cascade
    bool cascadeSymbol_Load = cascadeSymbol
            .load("/home/archie/Git/medicall/MedicallClient/Cascade.xml");
//    bool cascadeSymbol_Load = cascadeSymbol.load(haar_cascade_face_detection);

    if(!cascadeSymbol_Load)
    {
        std::cout << "Cascade not loaded!" << std::endl;
        return;
    }

    std::vector<cv::Rect> symbols;
    cascadeSymbol.detectMultiScale(gray, symbols);

    for(auto& p : symbols)
    {
        // Getting face coordinates
        cv::Point symbolBegin = cv::Point(p.x, p.y);
        cv::Point symbolEnd = cv::Point(p.x + p.width, p.y + p.height);

        std::cout << "X: " << p.x << " Y: "
                  << p.y << " Width: " << p.width
                  << " Height: " << p.height << std::endl;

        // Face cutting
        cvSaveImage("cut.png",
                    cutFace(cvLoadImage(filename, 1),
                    cvRect(p.x, p.y, p.width, p.height)));
        cv::Mat cuttedMat = cv::imread("cut.png");
        cv::Mat mask;

        mask = deleteBackground(cuttedMat);
        cvWaitKey(0);

        cv::imshow("Image", cuttedMat);
        cv::imwrite("cropped.png", cuttedMat);
        cvWaitKey(0);
    }
}

// Cut quadratic region
IplImage* FaceAnalyzer::cutFace(IplImage* image, CvRect faceArea)
{
    cvSetImageROI(image, faceArea);
    IplImage* image_cut = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);
    cvCopy(image, image_cut);
    cvResetImageROI(image);
    return image_cut;
}

// Face erasing
cv::Mat FaceAnalyzer::deleteBackground(cv::Mat image)
{
    cv::Mat hsv = cv::Mat(image.cols, image.rows, 8, 3);
    std::vector<cv::Mat> splitedHsv = std::vector<cv::Mat>();
    cv::cvtColor(image, hsv, CV_BGR2HSV);
    split(hsv, splitedHsv);

    for (int y = 0; y < hsv.cols; y++)
    {
        for (int x = 0; x < hsv.rows; x++)
        {
            int H = static_cast<int>(splitedHsv[0].at<uchar>(x, y));
            int S = static_cast<int>(splitedHsv[1].at<uchar>(x, y));
            int V = static_cast<int>(splitedHsv[2].at<uchar>(x, y));

            if (( V < COLOR_SATURATION) || (H < COLOR_MIN) || (H > COLOR_MAX))
            {
                image.at<cv::Vec3b>(x, y)[0] = 255;
                image.at<cv::Vec3b>(x, y)[1] = 255;
                image.at<cv::Vec3b>(x, y)[2] = 255;
            }
        }
    }

    return image;
}

// Mask applicaiton
void FaceAnalyzer::combine(cv::Mat* original, cv::Mat mask)
{
    for (int i = 0; i < original->cols; i++)
    {
        for (int j = 0; j < original->rows; i++)
        {
//            if (original->at(i,j));
        }
    }
}

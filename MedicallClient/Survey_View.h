#ifndef SURVEYVIEW_H
#define SURVEYVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "Modal.h"
#include "CameraPlayer.h"
#include "FaceAnalyzer.h"
#include "Button.h"

class Survey_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();

public:
    Survey_View(QWidget* parent = 0);
    ~Survey_View();

private:
    CameraPlayer* player;
    FaceAnalyzer* analyzer;

private slots:
    void startPlayer();
    void stopPlayer();
    void analyze();
};

#endif // SURVEYVIEW_H

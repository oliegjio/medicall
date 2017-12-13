#-------------------------------------------------
#
# Project created by QtCreator 2017-12-06T01:12:50
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    DoctorRegistration_View.cpp \
    Doctor_Model.cpp \
    Doctor_View.cpp \
    DoctorLogin_View.cpp \
    PatientLogin_View.cpp \
    MainWindow.cpp \
    NetworkManager.cpp \
    Patient_Model.cpp \
    PatientRegistration_View.cpp \
    Patient_View.cpp \
    Recomendation_Widget.cpp \
    Survey_View.cpp \
    Welcome_View.cpp \
    CameraFrameGrubber.cpp \
    Modal.cpp \
    CameraPlayer.cpp \
    FaceAnalyzer.cpp \
    Button.cpp \
    LineEdit.cpp \
    Label.cpp

HEADERS += \
    DoctorRegistration_View.h \
    Doctor_Model.h \
    Doctor_View.h \
    DoctorLogin_View.h \
    PatientLogin_View.h \
    MainWindow.h \
    NetworkManager.h \
    Patient_Model.h \
    PatientRegistration_View.h \
    Patient_View.h \
    Recomendation_Widget.h \
    Survey_View.h \
    Welcome_View.h \
    CameraFrameGrubber.h \
    Modal.h \
    CameraPlayer.h \
    FaceAnalyzer.h \
    Button.h \
    LineEdit.h \
    Label.h

INCLUDEPATH += /usr/include/opencv
LIBS += -L/usr/lib -lopencv_core -lopencv_imgproc -lopencv_calib3d -lopencv_video -lopencv_features2d -lopencv_ml -lopencv_highgui -lopencv_objdetect -lopencv_flann -lopencv_imgcodecs

DISTFILES +=

RESOURCES += \
    Resources.qrc

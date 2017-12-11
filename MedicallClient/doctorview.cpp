#include "doctorview.h"

DoctorView::DoctorView(QWidget* parent) : QWidget(parent) {}

DoctorView::~DoctorView() {}

void DoctorView::init()
{
    // ####
    // ## Setup:
    // ####

    Doctor* doctor = Doctor::getInstance();

    QVBoxLayout* baseLayout = new QVBoxLayout();

    QHBoxLayout* topBarLayout = new QHBoxLayout();
    topBarLayout->setAlignment(Qt::AlignTop);
    baseLayout->addLayout(topBarLayout, 1);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->setContentsMargins(0, 0, 0, 0);

    // ####
    // ## Topbar Widgets:
    // ####

    // # Username Title:
    QFont usernameLabel_Font("Airal", 20);
    QLabel* usernameLabel = new QLabel(doctor->username);
    usernameLabel->setFont(usernameLabel_Font);
    topBarLayout->addWidget(usernameLabel);

    topBarLayout->addStretch(1);

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    topBarLayout->addWidget(backButton);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Event(); });

    // # Recomendations:
//    QVector<RecomendationWidget*> recomendations;
//    for (int i = 0; i < 5; i++)
//    {
//        RecomendationWidget* recomendation = new RecomendationWidget();
//        recomendations.append(recomendation);
//        contentLayout->addWidget(recomendation);
//    }

    // ####
    // ## Other:
    // ####

    // # Scroll Area:
    QWidget* contentColumn = new QWidget();
    contentColumn->setLayout(contentLayout);
    scrollArea->setWidget(contentColumn);
    scrollArea->setWidgetResizable(true);
    baseLayout->addWidget(scrollArea, 1000);

    setLayout(baseLayout);
}

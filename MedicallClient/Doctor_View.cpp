#include "Doctor_View.h"

Doctor_View::Doctor_View(QWidget* parent) : QWidget(parent) {}

Doctor_View::~Doctor_View() {}

void Doctor_View::init()
{
    // ####
    // ## Setup:
    // ####

    Doctor_Model* doctor = Doctor_Model::getInstance();

    QVBoxLayout* base_Layout = new QVBoxLayout();

    QHBoxLayout* topBar_Layout = new QHBoxLayout();
    topBar_Layout->setAlignment(Qt::AlignTop);
    base_Layout->addLayout(topBar_Layout, 1);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    QVBoxLayout* content_Layout = new QVBoxLayout();
    content_Layout->setContentsMargins(0, 0, 0, 0);

    // ####
    // ## Topbar Widgets:
    // ####

    // # Username Title:
    QFont username_Font("Airal", 20);
    QLabel* username_Label = new QLabel(doctor->username);
    username_Label->setFont(username_Font);
    topBar_Layout->addWidget(username_Label);

    topBar_Layout->addStretch(1);

    // # Back Button:
    QPushButton* back_Button = new QPushButton("Назад");
    topBar_Layout->addWidget(back_Button);
    connect(back_Button,
            &QPushButton::clicked,
            [=] () { emit backButton_Clicked(); });

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
    contentColumn->setLayout(content_Layout);
    scrollArea->setWidget(contentColumn);
    scrollArea->setWidgetResizable(true);
    base_Layout->addWidget(scrollArea, 1000);

    setLayout(base_Layout);
}

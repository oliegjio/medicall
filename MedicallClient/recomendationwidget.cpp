#include "recomendationwidget.h"

RecomendationWidget::RecomendationWidget(QWidget* parent) : QWidget(parent)
{
    // ####
    // ## Setup:
    // ####

    QVBoxLayout* baseLayout = new QVBoxLayout();
    baseLayout->setAlignment(Qt::AlignTop);

    setStyleSheet("background-color: #f7f7f7;");

    setMinimumHeight(200);

    // ####
    // ## Widgets:
    // ####

    QLabel* titleLabel = new QLabel("Рекомендация");
    baseLayout->addWidget(titleLabel);

    // ####
    // ## Other:
    // ####

    setLayout(baseLayout);
}

RecomendationWidget::~RecomendationWidget() {}

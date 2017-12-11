#include "Recomendation_Widget.h"

Recomendation_Widget::Recomendation_Widget(QString title,
                                         QString date,
                                         QString content,
                                         QString doctor,
                                         QString patient,
                                         QWidget* parent) : QWidget(parent)
{
    // ####
    // ## Setup:
    // ####

    this->title = title;
    this->date = date;
    this->content = content;
    this->doctor = doctor;
    this->patient = patient;

    QVBoxLayout* baseLayout = new QVBoxLayout();
    baseLayout->setAlignment(Qt::AlignTop);    

    // ####
    // ## Widgets:
    // ####

    QFont titleLabel_Font("Arial", 18);
    QLabel* titleLabel = new QLabel(title);
    titleLabel->setFont(titleLabel_Font);
    baseLayout->addWidget(titleLabel);

    QFont dateLabel_Font("Arial", 8);
    QLabel* dateLabel = new QLabel(date);
    dateLabel->setFont(dateLabel_Font);
    baseLayout->addWidget(dateLabel);

    QFont contentLabel_Font("Arial", 12);
    QTextEdit* contentLine = new QTextEdit(content);
    contentLine->setFont(contentLabel_Font);
    contentLine->setFrameStyle(QFrame::NoFrame);
    contentLine->setTextInteractionFlags(Qt::TextSelectableByMouse);
    baseLayout->addWidget(contentLine);

    // ####
    // ## Other:
    // ####

    setLayout(baseLayout);
}

Recomendation_Widget::~Recomendation_Widget() {}

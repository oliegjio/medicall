#include "Survey_View.h"

Survey_View::~Survey_View()
{
    QString filename = "frame.jpg";
    QFile::remove(filename);
}

Survey_View::Survey_View(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignCenter);

    // # Camera Player:
    player = new CameraPlayer();
    player->setStyleSheet("border: 2px solid lightgray;");
    player->setMinimumSize(QSize(500, 500));
    base_Layout->addWidget(player);

    // # Buttons Layout:
    QHBoxLayout* buttons_Layout = new QHBoxLayout();
    buttons_Layout->setAlignment(Qt::AlignCenter);
    base_Layout->addLayout(buttons_Layout);

    // # Start Button:
    Button* start_Button = new Button("Начать");
    buttons_Layout->addWidget(start_Button);
    connect(start_Button,
            &Button::clicked,
            this,
            &Survey_View::startPlayer);

    // # Stop Button:
    Button* stop_Button = new Button("Остановить");
    buttons_Layout->addWidget(stop_Button);
    connect(stop_Button,
            &Button::clicked,
            this,
            &Survey_View::stopPlayer);

    // # Analyze Button:
    Button* analyze_Button = new Button("Анализировать");
    buttons_Layout->addWidget(analyze_Button);
    connect(analyze_Button,
            &Button::clicked,
            this,
            &Survey_View::analyze);

    // # Back Button:
    Button* back_Button = new Button("Назад");
    buttons_Layout->addWidget(back_Button);
    connect(back_Button,
            &Button::clicked,
            [=] () { stopPlayer();
                     emit backButton_Clicked(); });

    setLayout(base_Layout);
}

void Survey_View::startPlayer()
{
    if (!player->start())
        Modal::message("Нет доступных камер!");
}

void Survey_View::stopPlayer() { player->stop(); }

void Survey_View::analyze()
{
    if (!player->isActive) return;
    player->frameToPng("frame.png");
    analyzer = new FaceAnalyzer("frame.png");
}

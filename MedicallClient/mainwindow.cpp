#include "mainwindow.h"

MainWindow::MainWindow()
{
    // #####
    // ## Setup:
    // #####

    resize(QDesktopWidget().availableGeometry(this).size() * 0.7);
    setWindowTitle("Medicall");

    QWidget* interfaceArea = new QWidget();
    setCentralWidget(interfaceArea);

    stack = new QStackedWidget();

    QFont defaultFont("Arial", 18);
    setFont(defaultFont);

    // #####
    // ## Stack:
    // #####

    // # 0
    WelcomeView* welcomeView = new WelcomeView();
    stack->addWidget(welcomeView);
    connect(welcomeView, &WelcomeView::switchView, this, &MainWindow::setView);

    // # 1
    LoginView* loginView = new LoginView();
    stack->addWidget(loginView);
    connect(loginView, &LoginView::switchView, this, &MainWindow::setView);

    // #####
    // ## Other:
    // #####

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(stack);
    interfaceArea->setLayout(layout);

    setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow() {}

void MainWindow::setView(int index)
{
    stack->setCurrentIndex(index);
}

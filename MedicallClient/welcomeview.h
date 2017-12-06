#ifndef WelcomeView_H
#define WelcomeView_H

#include "QLabel"
#include "QVBoxLayout"
#include "QPushButton"

class WelcomeView : public QWidget
{
    Q_OBJECT

private slots:
    void loginButtonClicked();

signals:
    void switchView(int index);

public:
    WelcomeView();
    virtual ~WelcomeView() {}
};

#endif // WelcomeView_H

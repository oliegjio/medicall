#ifndef MODAL_H
#define MODAL_H

#include <QMessageBox>

class Modal : public QMessageBox
{
    Q_OBJECT

public:
    static void message(QString message);
};

#endif // MODAL_H

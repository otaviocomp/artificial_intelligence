#ifndef INICIA_H
#define INICIA_H

#include <QWidget>
#include "game.h"

namespace Ui {
class inicia;
}

class inicia : public QWidget
{
    Q_OBJECT

public:
    explicit inicia(QWidget *parent = 0);
    ~inicia();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inicia *ui;
    Game game;
};

#endif // INICIA_H

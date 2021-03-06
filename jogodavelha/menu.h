#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "inicia.h"

extern bool easy;

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
    void on_dificil_clicked();

    void on_facil_clicked();

private:
    Ui::menu *ui;
    inicia ini;
};

#endif // MENU_H

#include "menu.h"
#include "inicia.h"
#include "ui_menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_dificil_clicked()
{
    ini.show();
    this->hide();
}

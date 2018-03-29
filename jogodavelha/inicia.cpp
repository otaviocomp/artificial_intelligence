#include "inicia.h"
#include "game.h"
#include "ui_inicia.h"

inicia::inicia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inicia)
{
    ui->setupUi(this);
}

inicia::~inicia()
{
    delete ui;
}

void inicia::on_pushButton_clicked()
{
    game.show();
    this->hide();
}

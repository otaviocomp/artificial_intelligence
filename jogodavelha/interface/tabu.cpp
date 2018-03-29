#include "tabu.h"
#include "ui_tabu.h"

tabu::tabu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tabu)
{
    ui->setupUi(this);
}

tabu::~tabu()
{
    delete ui;
}

void tabu::on_quit_clicked()
{
    this->close();
}

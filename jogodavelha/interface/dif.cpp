#include "dif.h"
#include "ui_dif.h"

Dif::Dif(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dif)
{
    ui->setupUi(this);
}

Dif::~Dif()
{
    delete ui;
}

void Dif::on_pushButton_clicked()
{
    tab.show();
    this->hide();
}

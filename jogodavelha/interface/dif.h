#ifndef DIF_H
#define DIF_H

#include <QWidget>
#include <tabu.h>

namespace Ui {
class Dif;
}

class Dif : public QWidget
{
    Q_OBJECT

public:
    explicit Dif(QWidget *parent = 0);
    ~Dif();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dif *ui;
    tabu tab;
};

#endif // DIF_H

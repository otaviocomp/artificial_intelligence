#ifndef TABU_H
#define TABU_H

#include <QWidget>

namespace Ui {
class tabu;
}

class tabu : public QWidget
{
    Q_OBJECT

public:
    explicit tabu(QWidget *parent = 0);
    ~tabu();

private slots:
    void on_quit_clicked();

private:
    Ui::tabu *ui;
};

#endif // TABU_H

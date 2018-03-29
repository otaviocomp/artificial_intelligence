#include "menu.h"
#include "game.h"
#include "globals.h"
#include <QApplication>

int displayBoard[9];
CurrentPly currentPly;
Board board;
Ai ai;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    menu men;

    men.show();

    return app.exec();
}

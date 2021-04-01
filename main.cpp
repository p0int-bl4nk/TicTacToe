#include "header.h"
int main() {
    Gameboard game1;
    system("clear");
    game1.setPlayerNames();
    game1.printPlayerNames();
    game1.printGameBoard();
    game1.runGame();
    return 0;
}

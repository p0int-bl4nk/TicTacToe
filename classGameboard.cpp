#include "header.h"
#define WINNER 1
#define NO_WINNER 0
#define PLAYER1_MOVE 1
#define PLAYER2_MOVE 0

Gameboard::Gameboard() {
    for(int row{}; row < 4; row++)
        for(int column{}; column < 4; column++)
            gameSpace[row][column] = '-';
}

void Gameboard::setPlayerNames() {
    std::cout<<"Player1 name: ";
    getline(cin,player1);
    std::cout<<"\n";
    std::cout<<"Player2 name: ";
    getline(cin,player2);
}

void Gameboard::printPlayerNames() {
    cout<< "\n\n" <<player1 << " is 'X'.\n";
    cout<< player2 << " is 'O'.\n\n";
}

int Gameboard::checkForWinner(char mark) {
	int count{};

//	Check if any row has 4 consecutive 'mark'.
	for(int row{}; row < 4; row++) {
                for(int column{}; column < 4; column++) {
                	if(gameSpace[row][column] == mark)
                        	count++;
                }
                if(count == 4)
                        return WINNER;
                count = 0;
         }

//       Check if any column has 4 consecutive 'mark'.
         for(int row{} ; row < 4; row++) {
                for(int column{}; column < 4; column++) {
                        if(gameSpace[column][row] == mark)
                        	count++;
                }
                if(count == 4)
                	return WINNER;
                count = 0;
         }

//       Check if diagonal (00,11,22,33) has 4 consecutive 'mark'.
         for(int column{}; column < 4; column++) {
               	if(gameSpace[column][column] == mark)
        	        count++;
         }
         if(count == 4)
               	return WINNER;
         count = 0;

//       Check if diagonal (03,12,21,30) has 4 consecutive 'mark'.
	       for(int row{}, column{3}; row < 4; row++,column--) {
                if(gameSpace[row][column] == mark)
                	count++;
	       }
	       if(count == 4)
               	return WINNER;

         return NO_WINNER;
}

void Gameboard::runGame() {
    std::cout<< "\nFirst turn: " << player1 << " ('X')\n";
    for(int move{1}; move <= 16; move++) {
        std::cout << "\nPick your position, row(1-4): ";
        std::cin >> row;
        row--;
        std::cout << " column(1-4): ";
        std::cin >> column;
        column--;

        if(gameSpace[row][column] == '-') {
            if(move % 2 == PLAYER1_MOVE) {
                gameSpace[row][column] = 'X';
                system("clear");
                printGameBoard();
                if(checkForWinner('X') == WINNER) {
                	std::cout << player1 << " wins the game!";
                        exit(WINNER);
                }
                std::cout << player2 << " ('O'),";
            }
            else if(move % 2 == PLAYER2_MOVE) {
                gameSpace[row][column] = 'O';
                system("clear");
                printGameBoard();
                if(checkForWinner('O') == WINNER) {
                	std::cout << player2 << " wins the game!";
                        exit(WINNER);
                }
                std::cout << player1 << " ('X'),";
            }
        }
        else {
        	std::cout << "Invalid position!\nTry again.\n";
            	move--;
        }

        if(move == 15){
        	std::cout << "Match is Tied!" << '\n';
        	exit(NO_WINNER);
        }
    }
}

void Gameboard::printGameBoard() {
    std::cout << "\n\nGameboard : \n";
    for(int row{}; row < 4; row++) {
        for(int column{}; column < 4; column++)
            std::cout<<"\t"<<gameSpace[row][column]<<" ";

        std::cout<<"\n";
    }
}

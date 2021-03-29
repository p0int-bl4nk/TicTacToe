#include "header.h"
#define WIN 1
#define NO_WINNER 0
#define PLAYER1_MOVE 1
#define PLAYER2_MOVE 0

Gameboard::Gameboard() {
    for(int row{}; row < 4; row++)
        for(int column{}; column < 4; column++)
            gameSpace[row][column] = '-';
}

void Gameboard::setPlayerNames() {
    std::cout<<"Player1 name('x'): ";
    getline(cin,player1);
    std::cout<<"\n";
    std::cout<<"Player2 name('o'): ";
    getline(cin,player2);
}

void Gameboard::printPlayerNames() {
    cout<<"\n\nPlayer 1 ('x'): "<<player1;
    cout<<"\nPlayer 2 ('o'): "<<player2<<"\n\n";
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
                        return WIN;
                count = 0;
         }   
         
//       Check if any column has 4 consecutive 'mark'.
         for(int row{} ; row < 4; row++) {
                for(int column{}; column < 4; column++) {
                        if(gameSpace[column][row] == mark)
                        	count++;
                }
                if(count == 4)
                	return WIN;
                count = 0;
         }      
         
//       Check if diagonal (00,11,22,33) has 4 consecutive 'mark'.
         for(int column{}; column < 4; column++) {		 
               	if(gameSpace[column][column] == mark)
        	        count++;
         }
         if(count == 4)
               	return WIN;
         count = 0;
               	
//       Check if diagonal (03,12,21,30) has 4 consecutive 'mark'.
	 for(int row{}, column{3}; row < 4; row++,column--) {	
                if(gameSpace[row][column] == mark)
                	count++;
	 }
	 if(count == 4)
               	return WIN;
               	
         return NO_WINNER;	
}

void Gameboard::runGame() {
    std::cout<< "\nFirst turn " << player1 << " ('x')\n";
    for(int move{1}; move <= 16; move++) {
        std::cout << "\nPick your position, row(1-4): ";
        std::cin >> row;
        row--;
        std::cout << " column(1-4): ";
        std::cin >> column;
        column--;
        
        if(gameSpace[row][column] != 'x' && gameSpace[row][column] != 'o') {
            if(move % 2 == PLAYER1_MOVE) {
                gameSpace[row][column] = 'x';
                printGameBoard();
                if(checkForWinner('x') == WIN) {
                	std::cout << player1 << " wins the game!";
                        exit(WIN);
                }
                std::cout << "Player 2 "<< player2 << " ('o'),";
            }
            else if(move % 2 == PLAYER2_MOVE) {
                gameSpace[row][column] = 'o';
                printGameBoard();
                if(checkForWinner('o') == WIN) {
                	std::cout << player2 << " wins the game!";
                        exit(WIN);
                }
                std::cout << "Player 1 "<< player1 << " ('x'),";
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
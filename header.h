#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Gameboard {
    char gameSpace[4][4] = {};
    string player1, player2;
    int row{}, column{};
    public:
    	Gameboard();
    	void setPlayerNames();
    	void printPlayerNames();
    	int checkForWinner(char mark);
    	void runGame();
    	void printGameBoard();  	
};

#endif

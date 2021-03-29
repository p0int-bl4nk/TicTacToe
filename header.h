#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Gameboard{
    char gameSpace[4][4];
    string userName1,userName2;
    int row,column;
    public:
    Gameboard();
    void setUserName();
    void printUserName();
    void setGameSpace();
    void printGameSpace();
};

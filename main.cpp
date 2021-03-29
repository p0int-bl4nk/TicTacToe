#include<iostream>
#include"mainClasses.cpp"
int main()
{
    Gameboard user;
    user.setUserName();
    user.printUserName();
    user.printGameSpace();
    user.setGameSpace();
    return 0;
}

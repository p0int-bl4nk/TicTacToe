#include"header.h"


Gameboard::Gameboard()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            gameSpace[i][j]='-';
        }
    }
}

void Gameboard::setUserName()
{
    std::cout<<"Enter first user name(the 'x' user) : ";
    getline(cin,userName1);
    std::cout<<"\n";
    std::cout<<"Enter second user name(the 'o' user) : ";
    getline(cin,userName2);
}
void Gameboard::printUserName()
{
    cout<<"\n\nPlayer 1 ('x'): "<<userName1;
    cout<<"\nPlayer 2 ('o'): "<<userName2<<"\n\n";
}

void Gameboard::setGameSpace()
{
    std::cout<<"\nFirst turn "<<userName1<<" ('x')\n";
    for(int i=0;i<16;i++)
    {
        std::cout<<"\nPick your position, row(0-3) : ";
        std::cin>>row;
        std::cout<<" "<<" column(0-3) : ";
        std::cin>>column;
        if(!(gameSpace[row][column]=='x'||gameSpace[row][column]=='o'))
        {
            if(i%2==0)
            {
                gameSpace[row][column]='x';
                printGameSpace();
                int  count=0;
                for(int k=0;k<4;k++)//row check ('x')
                {
                    int count=0;
                    for(int j=0;j<4;j++)
                    {
                        if(gameSpace[k][j]=='x')
                          count++;
                    }
                    if(count==4)
                        {    std::cout<<userName1<<" wins the game!";
                            exit(1);}
                }
                for(int k=0;k<4;k++)//column check ('x')
                {
                    int count=0;
                    for(int j=0;j<4;j++)
                    {
                        if(gameSpace[j][k]=='x')
                          count++;
                    }
                    if(count==4)
                    {    std::cout<<userName1<<" wins the game!";
                        exit(1);}
                  }
                for(int k=0;k<4;k++)//diagonal check ('x')
                  {
                      int count=0;
                      for(int j=0;j<4;j++) // for 'x' diagonal (00,11,22,33)
                      {
                          if(gameSpace[j][j]=='x')
                            count++;
                      }
                      if(count==4)
                      {    std::cout<<userName1<<" wins the game!";
                          exit(1);}

                      count=0;

                      for(int j=3;j>-1;j--) //for 'x' diagonal (03,12,21,30)
                      {
                          if(gameSpace[i][j]=='x')
                            count++;
                      }
                      if(count==4)
                      {    std::cout<<userName1<<" wins the game!";
                          exit(1);}
                    }
                std::cout<<"Player 2 "<<userName2<<" ('o'),";
            }

            else if(i%2==1)
            {
                gameSpace[row][column]='o';
                printGameSpace();
                for(int k=0;k<4;k++)//row check ('o')
                {
                    int count=0;
                    for(int j=0;j<4;j++)
                    {
                        if(gameSpace[k][j]=='o')
                          count++;
                    }
                    if(count==4)
                        {    std::cout<<userName2<<" wins the game!";
                            exit(1);}
                }
                for(int k=0;k<4;k++)//column check ('o')
                {
                    int count=0;
                    for(int j=0;j<4;j++)
                    {
                        if(gameSpace[j][k]=='o')
                          count++;
                    }
                    if(count==4)
                    {    std::cout<<userName2<<" wins the game!";
                        exit(1);}
                  }
                for(int k=0;k<4;k++)//diagonal check ('o')
                    {
                        int count=0;
                        for(int j=0;j<4;j++) // for 'o' diagonal (00,11,22,33)
                        {
                            if(gameSpace[j][j]=='o')
                              count++;
                        }
                        if(count==4)
                        {    std::cout<<userName1<<" wins the game!";
                            exit(1);}

                        count=0;

                        for(int j=3;j>-1;j--) //for 'o' diagonal (03,12,21,30)
                        {
                            if(gameSpace[i][j]=='o')
                              count++;
                        }
                        if(count==4)
                        {    std::cout<<userName1<<" wins the game!";
                            exit(1);}
                      }
                std::cout<<"Player 1 "<<userName1<<" ('x'),";
            }
        }
        else{
                std::cout<<"Invalid position!\nTry again.\n";
            --i;
        }
        if(i==15){
        std::cout << "Match is Tied!" << '\n';exit(1);}
    }

}


void Gameboard::printGameSpace()
{
    std::cout<<"\n\nGameboard : \n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            std::cout<<"\t"<<gameSpace[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

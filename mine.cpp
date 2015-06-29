#include"mine.h"

Game::Game()
{
    srand(time(NULL));
}

void Game::setupgame()
{
    int x,y;

    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
        {
            gmap[i][j].adj=' ';
            gmap[i][j].mine=false;
        }
    }
    for(int i = 0;i < 10;i++)
    {
        x = rand() % 10;
        y = rand() % 10;
        if(gmap[x][y].mine==true)
        {
            i--;
        }
        gmap[x][y].mine=true;
    }
}

void Game::turn()
{

}

void Game::printmap()
{
    cout << "/ 0 1 2 3 4 5 6 7 8 9 X" << endl;
    for(int j = 0; j < 10; j++)
    {
        cout << j;
        for(int i = 0; i < 10; i++)
        {
            cout << "|" << gmap[j][i].adj;
        }
        cout << "|" << endl;
    }
    cout << "y" << endl;
}

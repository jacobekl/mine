#include"mine.h"

Game::Game()
{
    srand(time(NULL));
}

void Game::setupgame()
{
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
        {
            gmap[i][j].adj=' ';
            gmap[i][j].mine=false;
        }
    }

    //Välj 10 rutor och gör det minnor
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
            cout << "|" << gmap[0][1].adj;
        }
        cout << "|" << endl;
    }
    cout << "y" << endl;
}

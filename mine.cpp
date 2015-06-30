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

bool Game::turn()
{
    int x,y,adj,win;
    cout << "y: x: ";
    cin >> x;
    cin >> y;

    if(gmap[x][y].mine==true)
    {
        gmap[x][y].adj = '*';
        return true;
    }
    adj = 0;

    if(x == 0 || y == 0 || x == 9 || y == 9)
    {
        if(x== 0 && y == 0)
        {
            if(gmap[x+1][y].mine==true)
                adj++;

            if(gmap[x][y+1].mine==true)
                adj++;

            if(gmap[x+1][y+1].mine==true)
                adj++;
        }

        else if(x== 0 && y == 9)
        {
            if(gmap[x+1][y].mine==true)
                adj++;

            if(gmap[x][y-1].mine==true)
                adj++;

            if(gmap[x+1][y-1].mine==true)
                adj++;
        }

        else if(x== 9 && y == 0)
        {
            if(gmap[x-1][y].mine==true)
                adj++;

            if(gmap[x][y+1].mine==true)
                adj++;

            if(gmap[x-1][y+1].mine==true)
                adj++;
        }

                else if(x== 9 && y == 9)
        {
            if(gmap[x-1][y].mine==true)
                adj++;

            if(gmap[x][y-1].mine==true)
                adj++;

            if(gmap[x-1][y-1].mine==true)
                adj++;
        }

        else if(x ==0)
        {

        if(gmap[x][y+1].mine==true)
            adj++;
        if(gmap[x][y-1].mine==true)
            adj++;

        if(gmap[x+1][y-1].mine==true)
            adj++;
        if(gmap[x+1][y].mine==true)
            adj++;
        if(gmap[x+1][y+1].mine==true)
            adj++;

        }

        else if(x ==9)
        {

        if(gmap[x][y+1].mine==true)
            adj++;
        if(gmap[x][y-1].mine==true)
            adj++;

        if(gmap[x-1][y-1].mine==true)
            adj++;
        if(gmap[x-1][y].mine==true)
            adj++;
        if(gmap[x-1][y+1].mine==true)
            adj++;

        }

        else if(y ==0)
        {

        if(gmap[x+1][y].mine==true)
            adj++;
        if(gmap[x-1][y].mine==true)
            adj++;

        if(gmap[x+1][y+1].mine==true)
            adj++;
        if(gmap[x][y+1].mine==true)
            adj++;
        if(gmap[x-1][y+1].mine==true)
            adj++;

        }

        else if(y ==9)
        {

        if(gmap[x+1][y].mine==true)
            adj++;
        if(gmap[x-1][y].mine==true)
            adj++;

        if(gmap[x+1][y-1].mine==true)
            adj++;
        if(gmap[x][y-1].mine==true)
            adj++;
        if(gmap[x-1][y-1].mine==true)
            adj++;

        }

    }
    else
    {
        if(gmap[x-1][y-1].mine==true)
            adj++;
        if(gmap[x][y-1].mine==true)
            adj++;
        if(gmap[x+1][y-1].mine==true)
            adj++;

        if(gmap[x-1][y].mine==true)
            adj++;
        if(gmap[x+1][y].mine==true)
            adj++;

        if(gmap[x-1][y+1].mine==true)
            adj++;
        if(gmap[x][y+1].mine==true)
            adj++;
        if(gmap[x+1][y+1].mine==true)
            adj++;
    }
    gmap[x][y].adj = 48 + adj;

    win = 0;

    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
        {
            if(gmap[i][j].adj!=' ')
                win++;
        }
    }

    if(win==90)
    {
        cout << "congratulations" << endl;
        return true;
    }
    return false;


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

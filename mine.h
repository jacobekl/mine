#ifndef MINE_H_INCLUDED
#define MINE_H_INCLUDED

#include<iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Game
{
private:

    struct mine
    {
        char adj;
        bool mine;
    };

    mine gmap[10][10];

public:

    Game();
    void setupgame();
    void turn();
    void printmap();
    bool wincheack();


};

#endif // MINE_H_INCLUDED

#include"mine.h"

int main()
{
    Game Game;
    Game.setupgame();

    do
    {
        Game.printmap();
    }
    while (Game.turn()!=true);

    Game.printmap();
    return 0;
}

#ifndef GAME_H
#define GAME_H

#include <ncurses.h>

#include "globals.h"
//#include "field.h"
//#include "player.h"

class Field;
class Player;

// Global Field and Player pointers
extern Field* FIELD;
extern Player* PLAYER;

class Game
{
    public:
        Game();
    protected:
    private:
};

#endif // GAME_H

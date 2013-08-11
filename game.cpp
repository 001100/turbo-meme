#include "game.h"

#include "field.h"
#include "player.h"
#include "output.h"

Field* FIELD = NULL;
Player* PLAYER = NULL;

Game::Game()
{
    // Windows initialization.
    InitWindows();

    // Field and Player pointer initialization
    FIELD = new Field;
    PLAYER = new Player;
}

Game::~Game()
{
    delete FIELD;
    delete PLAYER;
}

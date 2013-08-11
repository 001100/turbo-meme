#include "game.h"

#include "field.h"
#include "player.h"

Field* FIELD = NULL;
Player* PLAYER = NULL;

Game::Game()
{
    FIELD = new Field;
    PLAYER = new Player;
}

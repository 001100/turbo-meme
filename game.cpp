#include "game.h"

Field* FIELD = NULL;
Player* PLAYER = NULL;

Game::Game()
{
    FIELD = new Field;
    PLAYER = new Player;
}

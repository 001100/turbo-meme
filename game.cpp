#include "game.h"

//#include <ncurses.h>

#include "field.h"
#include "player.h"
#include "output.h"

Field* FIELD = NULL;
Player* PLAYER = NULL;
Game* GAME = NULL;

Game::Game(): _startGame(false), _quitGame(false)
{
    // Windows initialization.
    InitWindows();

    // Field and Player pointer initialization
    FIELD = new Field;
    //PLAYER = new Player;

    TitleScreenMenu.AddMenuElement("New Game"); //0
    TitleScreenMenu.AddMenuElement("Load Game");//1
    TitleScreenMenu.AddMenuElement("Exit");     //2
}

Game::~Game()
{
    delete FIELD;
    delete PLAYER;
}

void Game::InitGameStart()
{
    SetStartStatus(true);
        wclear(FULL_WIN);
        wrefresh(FULL_WIN);
    FIELD->FillField();
    PLAYER = new Player;
}

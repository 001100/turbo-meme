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
    InitColors();

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
    FIELD = new Field;
    FIELD->FillField();
    PLAYER = new Player;
}

void Game::RestartGame()
{
    delete FIELD;
    delete PLAYER;

    FIELD = new Field;
    FIELD->FillField();
    PLAYER = new Player;
}

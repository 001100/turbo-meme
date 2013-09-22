#ifndef GAME_H
#define GAME_H

#include "globals.h"
#include "menu.h"

class Field;
class Player;
class Game;

// Global Field and Player pointers
extern Field* FIELD;
extern Player* PLAYER;
extern Game* GAME;

class Game
{
    public:
        Menu TitleScreenMenu;

        Game();     // Mainly sets main menu screen.
        ~Game();

        bool GetStartStatus(){ return _startGame; };
        bool GetQuitStatus(){ return _quitGame; };

        void SetStartStatus(bool startGame){ _startGame = startGame; };
        void SetQuitStatus(bool quitGame){ _quitGame = quitGame; };

        // Creates most of the game, generates field.
        void InitGameStart();

        // Restart the game.
        void RestartGame();

    protected:
    private:
        bool _startGame;
        bool _quitGame;
};

#endif // GAME_H

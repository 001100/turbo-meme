#ifndef GAME_H
#define GAME_H

#include "globals.h"
#include "title_screen.h"

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

        Game();
        ~Game();

        bool GetStartStatus(){ return _startGame; };
        bool GetQuitStatus(){ return _quitGame; };

        void SetStartStatus(bool startGame){ _startGame = startGame; };
        void SetQuitStatus(bool quitGame){ _quitGame = quitGame; };

    protected:
    private:

        bool _startGame;
        bool _quitGame;
};

#endif // GAME_H

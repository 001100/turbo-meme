#include <locale>           //for ncurses Unicode support

#include <ncurses.h>

#include "globals.h"
#include "game.h"
#include "field.h"
//#include "tile.h"
//#include "movable_tile.h"
//#include "player.h"
#include "keyboard_input.h"
#include "log.h"
//#include "title_screen.h"

#include "output.h"

int main()
{
    // Set locale to make ncurses properly use unicode characters.
    setlocale(LC_ALL, "");

    // Ncurses mod initiation.
    initscr();
    cbreak();               //C-style breaks (^C to SIGTERM).
    keypad(stdscr, TRUE);
    noecho();               // Disable echoing keypressings.
    curs_set(0);            // Disable cursor.

    GAME = new Game;

    do {
    GAME->TitleScreenMenu.DrawMenu();
    KeyPresses(TITLE_SCR);
    } while (!(GAME->GetStartStatus()));

    // Main loop.
    while (!(GAME->GetQuitStatus()))
    {
        FIELD->DrawField();
        Log::Read(8);
        PrintCurrentPosition();

        wnoutrefresh(MAIN_WIN);
        wnoutrefresh(LOG_WIN);
        doupdate();

        KeyPresses(MAIN_SCR);

        wclear(MAIN_WIN);
        wclear(LOG_WIN);
    }

    delete GAME;

    // Ncurses end.
    endwin();

    return 0;
}


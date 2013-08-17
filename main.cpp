#include <locale>           //for ncurses Unicode support

#include <ncurses.h>

#include "globals.h"
#include "game.h"
//#include "field.h"
#include "keyboard_input.h"
#include "log.h"

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



    // Main loop.
    while (!(GAME->GetQuitStatus()))
    {

        while (!(GAME->GetStartStatus()))
        {
            GAME->TitleScreenMenu.DrawMenu();
            KeyPresses(TITLE_SCR);
        }
        IsTerminalResized();
        DrawField();
        Log::Read(8);
        DrawInfoWin();

        wnoutrefresh(MAIN_WIN);
        wnoutrefresh(LOG_WIN);
        wnoutrefresh(INFO_WIN);
        doupdate();

        KeyPresses(MAIN_SCR);

        wclear(MAIN_WIN);
        wclear(LOG_WIN);
        wclear(INFO_WIN);
    }

    delete GAME;

    // Ncurses end.
    endwin();

    return 0;
}


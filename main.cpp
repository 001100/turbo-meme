#include <locale>           //for ncurses Unicode support
//#include <iostream>
#include <iomanip>          //for std::to_string()
#include <string>
//#include <vector>

#include <ncurses.h>

#include "globals.h"
#include "game.h"
#include "field.h"
//#include "tile.h"
//#include "movable_tile.h"
#include "player.h"
#include "keyboard_input.h"
#include "log.h"
#include "title_screen.h"

#include "output.h" // For InitWindows

void PrintCurrentPosition()
{
    mvwprintw(MAIN_WIN, 13, 15, "Your current position is: ");
    mvwprintw(MAIN_WIN, 13, 41, std::to_string(PLAYER->GetPosition('y')).c_str());
    mvwprintw(MAIN_WIN, 13, 43, std::to_string(PLAYER->GetPosition('x')).c_str());

    wrefresh(MAIN_WIN);
}

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

    // Windows initialization.
    InitWindows();

    Game* g = new Game;

    Menu TitleScreenMenu;
    TitleScreenMenu.AddMenuElement("New Game");
    TitleScreenMenu.AddMenuElement("Load Game");
    TitleScreenMenu.AddMenuElement("Exit");

    TitleScreenMenu.DrawMenu();


    // Main loop.
    bool exitStatus = false;
    do
    {

    TitleScreenMenu.DrawMenu();
    //TitleScreen();

    while (!exitStatus)
    {
        FIELD->DrawField();
        Log::Read(8);
        PrintCurrentPosition();

        wrefresh(MAIN_WIN);
        wrefresh(LOG_WIN);

        KeyPresses();

        wclear(MAIN_WIN);
        wclear(LOG_WIN);
    }
    } while (!exitStatus);

    delete g;

    // Ncurses end.
    endwin();

    return 0;
}


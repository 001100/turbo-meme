#include <locale>           //for ncurses Unicode support
#include <iostream>
#include <iomanip>          //for std::to_string()
#include <string>
#include <vector>

#include <ncurses.h>

#include "globals.h"
#include "field.h"
#include "tile.h"
#include "movable_tile.h"
#include "player.h"
#include "keyboard_input.h"
#include "log.h"
#include "title_screen.h"

#include "output.h" // For InitWindows

// Global Field and Player pointers
Field* FIELD;
Player* PLAYER;

void PrintCurrentPosition()
{
    Draw(MAIN_WIN, 13, 15, "Your current position is: ");
    Draw(MAIN_WIN, 13, 41, std::to_string(PLAYER->GetPosition('y')));
    Draw(MAIN_WIN, 13, 43, std::to_string(PLAYER->GetPosition('x')));

    Refresh(MAIN_WIN);
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

    // All this crap needs to be moved somewhere else.
    Field MyField;
        FIELD = &MyField;
    Player NewPlayer;
        PLAYER = &NewPlayer;

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

        Refresh(MAIN_WIN);
        Refresh(LOG_WIN);

        KeyboardInput::KeyPresses();

        Clear(MAIN_WIN);
        Clear(LOG_WIN);
    }
    } while (!exitStatus);

    // Ncurses end.
    endwin();

    return 0;
}


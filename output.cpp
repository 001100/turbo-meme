#include "output.h"

#include <string>
#include <iomanip>          //for std::to_string()

#include "game.h"
#include "globals.h"
#include "player.h"

void InitWindows()
{
    MAIN_WIN = newwin(LINES - 9, COLS, 0, 0);
    LOG_WIN  = newwin(8, COLS, LINES - 8, 0);
    FULL_WIN = newwin(LINES, COLS, 0, 0);

    // This pervents not drawig windows before getch() call
    timeout(30);
    getch();
    timeout(-1);
}

void PrintCurrentPosition()
{
    mvwprintw(MAIN_WIN, 13, 15, "Your current position is: ");
    mvwprintw(MAIN_WIN, 13, 41, std::to_string(PLAYER->GetPosition('y')).c_str());
    mvwprintw(MAIN_WIN, 13, 43, std::to_string(PLAYER->GetPosition('x')).c_str());
}

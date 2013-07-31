#include "title_screen.h"

void TitleScreen()
{
    Draw(FULL_WIN, LINES/2, COLS/2, "Start New Game");
    Refresh(FULL_WIN);
    getch();
    Clear(FULL_WIN);
}


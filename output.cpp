#include "output.h"

#include "globals.h"

void InitWindows()
{
    MAIN_WIN = newwin(LINES - 9, COLS, 0, 0);
    LOG_WIN  = newwin(8, COLS, LINES - 8, 0);
    FULL_WIN = newwin(LINES, COLS, 0, 0);
}

#include "output.h"

#include <string>
#include <iomanip>          //for std::to_string()

#include "game.h"
#include "globals.h"
#include "player.h"
#include "field.h"

// For IsTerminalResized()
static int _LINES = 0;
static int _COLS = 0;

// To move camera around field bigger than main screen
static int offsetY = 0;
static int offsetX = 0;

void InitWindows()                                  // +------+--+
{                                                   // |      |  |
    MAIN_WIN = newwin(LINES - 8, COLS - 35, 0, 0);  // |      |  |
    LOG_WIN  = newwin(8, COLS, LINES - 8, 0);       // +------+--+
    FULL_WIN = newwin(LINES, COLS, 0, 0);           // |         |
    INFO_WIN = newwin(LINES - 8, 35, 0, COLS - 35); // +---------+

    // Remember what values terminal had when initialaized for latter check.
    _LINES = LINES;
    _COLS = COLS;

    // This pervents not drawig windows before getch() call
    timeout(30);
    getch();
    timeout(-1);
}

void IsTerminalResized()
{
    if (_LINES != LINES || _COLS != COLS)
    {
        delwin(MAIN_WIN);
        delwin(LOG_WIN);
        delwin(FULL_WIN);
        delwin(INFO_WIN);

        InitWindows();
    }
}

void DrawInfoWin()
{
    mvwprintw(INFO_WIN, 0, 0, "Your current position is: ");
    mvwprintw(INFO_WIN, 0, 27, std::to_string(PLAYER->GetPosition(Y)).c_str());
    mvwprintw(INFO_WIN, 0, 31, std::to_string(PLAYER->GetPosition(X)).c_str());

    mvwprintw(INFO_WIN, 1, 0, std::to_string(MAIN_WIN->_maxy).c_str());
    mvwprintw(INFO_WIN, 1, 3, std::to_string(MAIN_WIN->_maxx).c_str());
    mvwprintw(INFO_WIN, 2, 0, std::to_string(_LINES).c_str());
    mvwprintw(INFO_WIN, 2, 3, std::to_string(_COLS).c_str());

    mvwprintw(INFO_WIN, 3, 0, "Offsets(y,x)");
    mvwprintw(INFO_WIN, 4, 0, std::to_string(offsetY).c_str());
    mvwprintw(INFO_WIN, 4, 4, std::to_string(offsetX).c_str());
}

int CheckFieldToScreenSize(int& y, int& x)
{
    // WTF
    if (g_HEIGHT <= MAIN_WIN->_maxy && g_WIDTH <= MAIN_WIN->_maxx) {
        y = g_HEIGHT;
        x = g_WIDTH;
        offsetY = 0;
        offsetX = 0;
        return 0;
    }
    if (g_HEIGHT > MAIN_WIN->_maxy && g_WIDTH > MAIN_WIN->_maxx) {
        y = MAIN_WIN->_maxy;
        if (y + offsetY > g_HEIGHT)
            offsetY -=  (y + offsetY) - g_HEIGHT;
        x = MAIN_WIN->_maxx;
        if (x + offsetX > g_WIDTH)
            offsetX -= (x + offsetX) - g_WIDTH;
        return 0;
    }
    if (g_HEIGHT > MAIN_WIN->_maxy && g_WIDTH <= MAIN_WIN->_maxx) {
        y = MAIN_WIN->_maxy;
        if (y + offsetY > g_HEIGHT)
            offsetY -= (y + offsetY) - g_HEIGHT;;
        x = g_WIDTH;
        offsetX = 0;
        return 0;
    }
    if (g_WIDTH > MAIN_WIN->_maxx && g_HEIGHT <= MAIN_WIN->_maxy) {
        y = g_HEIGHT;
        offsetY = 0;
        x = MAIN_WIN->_maxx;
        if (x + offsetX > g_WIDTH)
            offsetX -= (x + offsetX) - g_WIDTH;
        return 0;
    }
    return 1;
}

int DrawField()
{
    int maxY = 0;
    int maxX = 0;

    CheckFieldToScreenSize(maxY, maxX);

    for (int height = 0 + offsetY; height < maxY + offsetY; ++height)
    {
        for (int width = 0 + offsetX; width < maxX + offsetX; ++width)
        {
            wprintw(MAIN_WIN, ((*FIELD)(height, width).GetTileChar()).c_str());
        }
        wprintw(MAIN_WIN, "\n");
    }

    return 1;
}

int SetOffset(int y, int x)
{
    if (offsetY == 0 && y == -1)
        return 0;
    if (offsetX == 0 && x == -1)
        return 0;

    offsetY += y;
    offsetX += x;
    return 0;
}

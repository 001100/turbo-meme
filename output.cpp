#include "output.h"

#include <string>
#include <iomanip>          //for std::to_string()

#include "game.h"
#include "globals.h"
#include "player.h"
#include "field.h"
#include "log.h"    //dbug

// For IsTerminalResized()
static int _LINES = 0;
static int _COLS = 0;

// To move camera around field bigger than main screen
static int offsetY = 0;
static int offsetX = 0;

// For free camera mod
static bool freeCameraMod = false;

void InitWindows()                                  // +------+--+
{                                                   // | MAIN |IN|
    MAIN_WIN = newwin(LINES - 8, COLS - 35, 0, 0);  // |      |FO|
    LOG_WIN  = newwin(8, COLS, LINES - 8, 0);       // +------+--+
    FULL_WIN = newwin(LINES, COLS, 0, 0);           // |   LOG   |
    INFO_WIN = newwin(LINES - 8, 35, 0, COLS - 35); // +---------+

    // Remember what values terminal had when initialaized, for IsTerminalResized().
    _LINES = LINES;
    _COLS = COLS;

    // This pervents not drawig windows before getch() call
    timeout(30);
    getch();
    timeout(-1);
}

void InitColors()
{
    start_color();

    init_pair(RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(BLUE_ON_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair(GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair(YELLOW_ON_BLACK, COLOR_YELLOW, COLOR_BLACK);
}

void IsTerminalResized()
{
    if (_LINES != LINES || _COLS != COLS)
    {
        while (LINES < 24 || COLS < 80)
        {
            wprintw(FULL_WIN, "Minimum screen size is 24 x 80!");
            wrefresh(FULL_WIN);
            timeout(3000);
            getch();
            timeout(-1);
            wclear(FULL_WIN);
        }
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
    mvwprintw(INFO_WIN, 0, 26, std::to_string(PLAYER->GetPosition(Y)).c_str());
    mvwprintw(INFO_WIN, 0, 30, std::to_string(PLAYER->GetPosition(X)).c_str());

    mvwprintw(INFO_WIN, 1, 0, "Field win size(y, x): ");
    mvwprintw(INFO_WIN, 1, 22, std::to_string(MAIN_WIN->_maxy).c_str());
    mvwprintw(INFO_WIN, 1, 26, std::to_string(MAIN_WIN->_maxx).c_str());

    mvwprintw(INFO_WIN, 2, 0, "Whole win size(y, x): ");
    mvwprintw(INFO_WIN, 2, 22, std::to_string(_LINES).c_str());
    mvwprintw(INFO_WIN, 2, 26, std::to_string(_COLS).c_str());

    mvwprintw(INFO_WIN, 3, 0, "Offsets(y,x)");
    mvwprintw(INFO_WIN, 4, 0, std::to_string(offsetY).c_str());
    mvwprintw(INFO_WIN, 4, 4, std::to_string(offsetX).c_str());

    mvwprintw(INFO_WIN, 5, 0, "Color test:");
    if (has_colors() == FALSE) {
        wattron(INFO_WIN, COLOR_PAIR(RED_ON_BLACK) | A_BOLD);
        mvwprintw(INFO_WIN, 5, 12, "No");
        wattroff(INFO_WIN, COLOR_PAIR(RED_ON_BLACK) | A_BOLD);
        }
    else {
        wattron(INFO_WIN, COLOR_PAIR(RED_ON_BLACK) | A_BOLD);
        mvwprintw(INFO_WIN, 5, 12, "Yes");
        wattroff(INFO_WIN, COLOR_PAIR(RED_ON_BLACK) | A_BOLD);
    }

}

void CheckFieldToScreenSize(int& maxY, int& maxX)
{
    // Well, this is somehow better.
    // For max height.
    // If Field size is bigger than main window size...
    if (g_HEIGHT > MAIN_WIN->_maxy) {
        // set base maxY to that of main window.
        maxY = MAIN_WIN->_maxy;
            // And this is basically for sudden terminal resizes
        if (maxY + offsetY > g_HEIGHT)
            offsetY -=  (maxY + offsetY) - g_HEIGHT;
    } else {
        // And if it is smaler then set base maxY to it and zero offset
        maxY = g_HEIGHT;
        offsetY = 0;
    }
    // Same for x.
    if (g_WIDTH > MAIN_WIN->_maxx) {
        maxX = MAIN_WIN->_maxx;
        if (maxX + offsetX > g_WIDTH)
            offsetX -= (maxX + offsetX) - g_WIDTH;
    } else {
        maxX = g_WIDTH;
        offsetX = 0;
    }
}

void DrawField()
{
    int maxY = 0;
    int maxX = 0;

    CheckFieldToScreenSize(maxY, maxX);

    for (int height = 0 + offsetY; height < maxY + offsetY; ++height)
    {
        for (int width = 0 + offsetX; width < maxX + offsetX; ++width)
        {
            wattron(MAIN_WIN, COLOR_PAIR((*FIELD)(height, width).GetColor()));
            mvwprintw(MAIN_WIN, height - offsetY, width - offsetX,
                            ((*FIELD)(height, width).GetTileChar()).c_str());
            wattroff(MAIN_WIN, COLOR_PAIR((*FIELD)(height, width).GetColor()));
        }
    }
}

void SetOffset(int y, int x)
{
    if (offsetY + y < 0)        // Here we check
        offsetY = 0;            // +--------------
    else                        // | TOP and LEFT offsets.
        offsetY += y;           // | because this borders won't change.
                                // |
    if (offsetX + x < 0)
        offsetX = 0;
    else
        offsetX += x;
}

void DrawPassabilityField()
{
    wclear(MAIN_WIN);
    int maxY = 0;
    int maxX = 0;

    CheckFieldToScreenSize(maxY, maxX);

    for (int height = 0 + offsetY; height < maxY + offsetY; ++height)
    {
        for (int width = 0 + offsetX; width < maxX + offsetX; ++width)
        {
            if ((*FIELD)(height, width).IsPassable()) {
                wattron(MAIN_WIN, COLOR_PAIR(GREEN_ON_BLACK));
                mvwprintw(MAIN_WIN, height - offsetY, width - offsetX, "█");
                wattroff(MAIN_WIN, COLOR_PAIR(GREEN_ON_BLACK));
            }
            else {
                wattron(MAIN_WIN, COLOR_PAIR(RED_ON_BLACK));
                mvwprintw(MAIN_WIN, height - offsetY, width - offsetX, "█");
                wattroff(MAIN_WIN, COLOR_PAIR(RED_ON_BLACK));
            }

        }
    }
    wrefresh(MAIN_WIN);
    getch();
}

void CenterOnPlayer()
{
    if (!freeCameraMod)
    {
    offsetY = 0;
    offsetX = 0;
    SetOffset(PLAYER->GetPosition(Y) - MAIN_WIN->_maxy/2,
              PLAYER->GetPosition(X) - MAIN_WIN->_maxx/2);
    }
}

void SetFreeCameraMod()
{
    freeCameraMod = !freeCameraMod;
}

int DebugDraw(int y, int x)
{
    if (!_DBG)
        return 0;
    DrawField();
    std::string logDbgMsg = "Changed tile to \"" + (*FIELD)(y, x).GetTileChar() +
        "\"" " at possition y(" + std::to_string(y) + "), x(" +
        std::to_string(x) + "), Tile ID - " + std::to_string((*FIELD)(y, x).GetID()) + ".";

    Log::Write(logDbgMsg.c_str());
    Log::Read(8);
    wnoutrefresh(MAIN_WIN);
    wnoutrefresh(LOG_WIN);
    doupdate();

    usleep(50000);
    wclear(MAIN_WIN);
    wclear(LOG_WIN);

    return 0;
}

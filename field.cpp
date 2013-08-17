#include "field.h"

#include <ncurses.h>
#include <iomanip>  //dbug
#include <cassert>
#include <unistd.h> // for usleep

#include "output.h"
#include "log.h"    //dbug

Field::Field():
    F(*this)
{
    // Filing vector of tiles.
    for (int NumOfTiles=0; NumOfTiles < g_AREA; ++NumOfTiles)
    {
        m_FieldData.push_back(Tile(NumOfTiles));
    }
    //FillField();            //Fills initial field
}

Field::~Field()
{
    //dtor
}

Tile& Field::operator()(int height, int width)
{
    assert(height >= 0 && height < g_HEIGHT);
    assert(width >= 0 && width < g_WIDTH);

    return m_FieldData[height*g_HEIGHT+width]; // If HEIGHT == WIDTH
}

int Field::DebugDraw(int y, int x)
{
    if (!_DBG)
        return 0;
    DrawField();
    std::string logDbgMsg = "Changed tile to \"" + F(y, x).GetTileChar() +
        "\"" " at possition y(" + std::to_string(y) + "), x(" +
        std::to_string(x) + "), Tile ID - " + std::to_string(F(y, x).GetID()) + ".";

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

void Field::FillField()
{
    for (int iii = 0; iii < g_HEIGHT; iii++)
    {
        for (int jjj = 0; jjj < g_WIDTH; jjj++)
        {
            //Corners drawing.
            if (iii == 0 && jjj == 0) {
                //
                F(iii, jjj).SetTileChar("╔");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            if (iii == 0 && jjj == g_WIDTH-1) {
                F(iii, jjj).SetTileChar("╗");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            if (iii == g_HEIGHT-1 && jjj == 0) {
                F(iii, jjj).SetTileChar("╚");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            if (iii == g_HEIGHT-1 && jjj == g_WIDTH-1) {
                F(iii, jjj).SetTileChar("╝");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            //Horizontal pipes drawing.
            if ((iii == 0 || iii == g_HEIGHT-1) && (jjj > 0 && jjj < g_WIDTH-1)) {
                F(iii, jjj).SetTileChar("═");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            //Vertical pipes drawing.
            if ((jjj == 0 || jjj == g_WIDTH-1) && (iii > 0 && iii < g_HEIGHT-1)) {
                F(iii, jjj).SetTileChar("║");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            // Special object.
            if (iii == 2 && jjj == 2) {
                F(iii, jjj).SetTileChar("╳");
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
                continue;
            }
            //All other floor tiles.
            F(iii, jjj).SetTileChar("+");
            F(iii, jjj).SetTilePassability(true);
        }
    }
}



void Field::DrawPassabilityField()
{
    wclear(MAIN_WIN);
    for (int height = 0; height < g_HEIGHT; ++height)
    {
        for (int width = 0; width < g_WIDTH; ++width)
        {
            if (F(height, width).IsPassable())
                wprintw(MAIN_WIN, "1");
            else
                wprintw(MAIN_WIN, "0");

        }
        wprintw(MAIN_WIN, "\n");
    }
    wrefresh(MAIN_WIN);
    getch();
}

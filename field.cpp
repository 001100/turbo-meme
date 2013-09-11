#include "field.h"

#include <ncurses.h>
#include <cassert>

#include "output.h"

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
                F(iii, jjj).SetColor(BLUE_ON_BLACK);
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

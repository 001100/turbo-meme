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

    return m_FieldData[height*g_HEIGHT+width]; //works only If HEIGHT == WIDTH
}

bool Field::IsInsideTheField(int y, int x)
{
    if ((y >= 0 && y < g_HEIGHT) &&
        (x >= 0 && x < g_WIDTH))
        return true;

    return false;
}


void Field::FillField()
{
    for (int iii = 0; iii < g_HEIGHT; iii++)
    {
        for (int jjj = 0; jjj < g_WIDTH; jjj++)
        {
            //Corners drawing.
            if (iii == 0 && jjj == 0) {
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
            //All other floor tiles.
            F(iii, jjj).SetTileChar("+");
            F(iii, jjj).SetTilePassability(true);
        }
    }
    MakeLabyrinth();
}

void Field::MakeLabyrinth()
{
    srand (time(NULL));
    for (int iii = 1; iii < g_HEIGHT-1; iii++)
    {
        for (int jjj = 1; jjj < g_WIDTH-1; jjj++)
        {
        int placePercentValue = rand() % 100;
        // 30% chance to place obstacle
        if (placePercentValue < 40) {
                F(iii, jjj).SetTileChar("╳");
                // Random color
                //F(iii, jjj).SetColor(static_cast<Color>(rand() % (COLOR_COUNT - 1) + 1));
                F(iii, jjj).SetTilePassability(false);
                DebugDraw(iii, jjj);
            }
        }
    }

    for (int iii = 0; iii < g_HEIGHT; iii++)
    {
        for (int jjj = 0; jjj < g_WIDTH; jjj++)
        {
            SmothWalls(iii, jjj);
        }
    }
}

int Field::SmothWalls(int y, int x)
{
    if (F(y, x).IsPassable())
        return 1;

    const unsigned short int
        no_walls = 0b0000,
        top      = 0b1000,
        bottom   = 0b0100,
        left     = 0b0010,
        right    = 0b0001;

    unsigned int ResultWals = no_walls;

    // Check top
    if (y - 1 < 0 || F(y - 1, x).IsPassable());
        else ResultWals |= top;
    // Check bottom
    if (y + 1 == g_HEIGHT || F(y + 1, x).IsPassable());
        else ResultWals |= bottom;
    // Check right
    if (x - 1 < 0 || F(y, x - 1).IsPassable());
        else ResultWals |= left;
    // Check left
    if (x + 1 == g_WIDTH || F(y, x + 1).IsPassable());
        else ResultWals |= right;


    switch (ResultWals) {
        // Zero hits - column, removed temporarly
        case no_walls: {
            F(y, x).SetTileChar("+");
            F(y, x).SetTilePassability(true);
            break;
        }

        // One hit - column, conected to a wall
        case top:    F(y, x).SetTileChar("╨"); break;
        case bottom: F(y, x).SetTileChar("╥"); break;
        case left:   F(y, x).SetTileChar("╕"); break;
        case right:  F(y, x).SetTileChar("╒"); break;

        // Two hits - line/corner
        case top|bottom:   F(y, x).SetTileChar("║"); break;
        case left|right:   F(y, x).SetTileChar("═"); break;
        case top|left:     F(y, x).SetTileChar("╝"); break;
        case top|right:    F(y, x).SetTileChar("╚"); break;
        case bottom|left:  F(y, x).SetTileChar("╗"); break;
        case bottom|right: F(y, x).SetTileChar("╔"); break;

        // Thre hit - thre-way cross
        case top|bottom|left:   F(y, x).SetTileChar("╣"); break;
        case top|bottom|right:  F(y, x).SetTileChar("╠"); break;
        case top|right|left:    F(y, x).SetTileChar("╩"); break;
        case bottom|right|left: F(y, x).SetTileChar("╦"); break;

        // Four hits - four-way cross
        case top|bottom|left|right: F(y, x).SetTileChar("╬"); break;
    }

    return 0;
}



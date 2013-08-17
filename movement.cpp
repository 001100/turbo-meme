#include "movable_tile.h"

#include "game.h"
#include "field.h"
#include "log.h"

void MovableTile::TileMovement(int ly, int lx)
{
    // Passability check.
    Field& F = *FIELD;
    Tile& DesignationTile = F(GetPosition(Y) + ly, GetPosition(X) + lx);
    if (!(DesignationTile.IsPassable()))
        //wprintw(LOG_WIN, "Tile is impassable!");
        Log::Write("Tile is impassable!");
    else
    {
    // Erase old position.
    Tile tmpFloorTile(GetID(), "+");
    F(GetPosition(Y), GetPosition(X)) = tmpFloorTile;

    // Change actual position.
    if (ly == -1 && lx == 0) {
        Log::Write("You pressed UP(u)");
        SetPosition(Y, -1);
    }
    if (ly == 1 && lx == 0) {
        Log::Write("You pressed DOWN(m)");
        SetPosition(Y, 1);
    }
    if (ly == 0 && lx == -1) {
        Log::Write("You pressed LEFT(h)");
        SetPosition(X, -1);
    }
    if (ly == 0 && lx == 1) {
        Log::Write("You pressed RIGHT(k)");
        SetPosition(X, 1);
    }

    // Place tile at new position.
    Tile* tmpPlayerTile = this;
    F(GetPosition(Y), GetPosition(X)) = *tmpPlayerTile;
    }
}


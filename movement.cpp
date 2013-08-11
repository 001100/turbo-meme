#include "movable_tile.h"

#include "game.h"
#include "field.h"
#include "log.h"

void MovableTile::TileMovement(int ly, int lx)
{
    // Passability check.
    Field& F = *FIELD;
    Tile& DesignationTile = F(GetPosition('y') + ly, GetPosition('x') + lx);
    if (!(DesignationTile.IsPassable()))
        //wprintw(LOG_WIN, "Tile is impassable!");
        Log::Write("Tile is impassable!");
    else
    {
    // Erase old position.
    Tile tmpFloorTile(GetID(), "+");
    F(GetPosition('y'), GetPosition('x')) = tmpFloorTile;

    // Change actual position.
    if (ly == -1 && lx == 0) {
        Log::Write("You pressed UP(u)");
        SetPosition('y', -1);
    }
    if (ly == 1 && lx == 0) {
        Log::Write("You pressed DOWN(m)");
        SetPosition('y', 1);
    }
    if (ly == 0 && lx == -1) {
        Log::Write("You pressed LEFT(h)");
        SetPosition('x', -1);
    }
    if (ly == 0 && lx == 1) {
        Log::Write("You pressed RIGHT(k)");
        SetPosition('x', 1);
    }

    // Place tile at new position.
    Tile* tmpPlayerTile = this;
    F(GetPosition('y'), GetPosition('x')) = *tmpPlayerTile;
    }
}


#include "movable_tile.h"

#include <cassert>

#include "game.h"
#include "field.h"


MovableTile::MovableTile(int y, int x): Tile()
{
    // Check placement tile for passability
    CheckInitPassability(y, x);
}

MovableTile::~MovableTile()
{
    //dtor
}

int MovableTile::CheckInitPassability(int y, int x)
{
    // If our initial coords passable place movable at them.
    if ((*FIELD)(y, x).IsPassable()) {
        m_Y = y;
        m_X = x;
        return 0;
    };

    // And if not, search for empty tile in 3x3 sqare
    for(int yyy = -1; yyy <= 1; yyy++)
    {
        for(int xxx = -1; xxx <= 1; xxx++)
        {
            bool isInsideTheField = (*FIELD).IsInsideTheField(y + yyy, x + xxx);
            bool isPassable = (*FIELD)(y + yyy, x + xxx).IsPassable();

            if (isInsideTheField && isPassable)
            {
                m_Y = y + yyy;
                m_X = x + xxx;
                return 0;
            };
        }
    }

    // And if we don't find empty tile at least place it at original coords,
    // TODO: This must be changed (serch wider, regenerate field, etc.)
    m_Y = y;
    m_X = x;

    return 0;
}

int& MovableTile::GetPosition(tileAxis axis)
{
    assert(axis != Y || axis != X);
    if (axis == Y)
        return m_Y;
    //if (axis == 'x')          // Simplification, otherwise - warning
        return m_X;
}

void MovableTile::SetPosition(tileAxis axis, int positionDelta)
{
    assert(axis != Y || axis != X);
    if (axis == Y)
        m_Y += positionDelta;
    if (axis == X)
        m_X += positionDelta;
}

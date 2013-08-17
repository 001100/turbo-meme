#include "movable_tile.h"

#include <cassert>

#include "game.h"


MovableTile::MovableTile(int y, int x): Tile()
{
    m_Y = y;
    m_X = x;
}

MovableTile::~MovableTile()
{
    //dtor
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

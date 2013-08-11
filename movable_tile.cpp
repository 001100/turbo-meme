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

int& MovableTile::GetPosition(char axis)
{
    assert(axis != 'y' || axis != 'x');
    if (axis == 'y')
        return m_Y;
    //if (axis == 'x')          // Simplification, otherwise - warning
        return m_X;
}

void MovableTile::SetPosition(char axis, int positionDelta)
{
    assert(axis != 'y' || axis != 'x');
    if (axis == 'y')
        m_Y += positionDelta;
    if (axis == 'x')
        m_X += positionDelta;
}

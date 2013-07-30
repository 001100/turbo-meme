#include "movable_tile.h"
extern Field* FIELD;

MovableTile::MovableTile(int y, int x): Tile(),
    //m_Field(MyField)
    m_Field(*FIELD)
{
    m_Position[0] = y;
    m_Position[1] = x;
}

MovableTile::~MovableTile()
{
    //dtor
}

int& MovableTile::GetPosition(char axis)
{
    assert(axis != 'y' || axis != 'x');
    if (axis == 'y')
        return m_Position[0];
    //if (axis == 'x')          // Simplification, otherwise - warning
        return m_Position[1];
}

void MovableTile::SetPosition(char axis, int positionDelta)
{
    assert(axis != 'y' || axis != 'x');
    if (axis == 'y')
        m_Position[0] += positionDelta;
    if (axis == 'x')
        m_Position[1] += positionDelta;
}

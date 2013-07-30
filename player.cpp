#include "player.h"

Player::Player() :
    MovableTile(g_HEIGHT / 2, g_WIDTH / 2), m_playerTile(this)
{
    SetID(GetPosition('y')*GetPosition('x'));
    SetTileChar("@");

    m_Field(GetPosition('y'), GetPosition('x')) = *m_playerTile;
}

Player::~Player()
{
}

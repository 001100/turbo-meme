#include "player.h"

#include "globals.h"
#include "game.h"
#include "field.h"

Player::Player() :
    MovableTile(g_HEIGHT / 2, g_WIDTH / 2), m_playerTile(this)
{
    SetID(GetPosition('y')*GetPosition('x'));
    SetTileChar("@");

    (*FIELD)(GetPosition('y'), GetPosition('x')) = *m_playerTile;
}

Player::~Player()
{
}

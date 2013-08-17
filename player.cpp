#include "player.h"

#include "globals.h"
#include "game.h"
#include "field.h"

Player::Player() :
    MovableTile(g_HEIGHT / 2, g_WIDTH / 2), m_playerTile(this)
{
    SetID(GetPosition(Y)*GetPosition(X));
    SetTileChar("@");

    (*FIELD)(GetPosition(Y), GetPosition(X)) = *m_playerTile;
}

Player::~Player()
{
}

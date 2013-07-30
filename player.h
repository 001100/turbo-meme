#ifndef PLAYER_H
#define PLAYER_H

#include "tile.h"
#include "movable_tile.h"
#include "globals.h"

class Player : public MovableTile
{
    private:
        Tile *m_playerTile;

    protected:
    public:
        Player();
        virtual ~Player();
};

#endif // PLAYER_H

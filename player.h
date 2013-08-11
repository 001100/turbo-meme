#ifndef PLAYER_H
#define PLAYER_H

#include "movable_tile.h"

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

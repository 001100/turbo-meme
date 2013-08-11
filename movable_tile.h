#ifndef MOVABLE_TILE_H
#define MOVABLE_TILE_H

#include "tile.h"

class MovableTile: public Tile
{
    private:
        int m_Y;
        int m_X;
    protected:
    public:
        MovableTile(int y, int x);
        virtual ~MovableTile();

        //Getters
        int& GetPosition(char axis);

        //Setters
        void SetPosition(char axis, int value);
        void TileMovement(int y, int x);
};

#endif // MOVABLE_TILE_H

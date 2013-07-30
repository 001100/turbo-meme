#ifndef MOVABLE_TILE_H
#define MOVABLE_TILE_H

#include <cassert>

#include "tile.h"
#include "field.h"
#include "output.h"
#include "log.h"

class MovableTile: public Tile
{
    private:
        int m_Position[2]; // [0] is y and [1] is x
    protected:
        Field& m_Field;
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

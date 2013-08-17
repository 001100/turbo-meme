#ifndef FIELD_INCLUDED
#define FIELD_INCLUDED

#include <vector>

#include "globals.h"
#include "tile.h"

class Field
{
    private:
        std::vector<Tile> m_FieldData; // Tile objects storage.
        Field &F;                       // Ref to *this
    protected:
    public:
        Field();
        ~Field();

        //Getters
        std::vector<Tile>& GetFieldData(){ return m_FieldData; }
        Field& GetField(){ return *this; }
        // Fills initial field
        void FillField();
        //Public member functions
        void DrawPassabilityField();    // For debug purposes.
        // Access to tiles via 2d coordinates (y,x)
        Tile& operator()(int height, int width);
        // For debug - draws every field tile when fill field.
        int DebugDraw(int y, int x);
};

#endif // FIELD_INCLUDED

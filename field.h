#ifndef FIELD_INCLUDED
#define FIELD_INCLUDED

//#include <iostream>
//#include <string>
#include <iomanip>  //dbug
//#include <vector>
#include <cassert>
//#include <ncurses.h> //for getch()
#include <unistd.h> // for usleep

#include "globals.h"
#include "tile.h"
//#include "output.h"
#include "log.h"    //dbug

class Field
{
    private:
        std::vector<Tile> m_FieldData; // Tile objects storage.
        Field &F;                       // Ref to *this

        void FillField();

    protected:

    public:
        Field();
        ~Field();

        //Getters
        std::vector<Tile>& GetFieldData(){ return m_FieldData; }
        Field& GetField(){ return *this; }

        //Public member functions
        void DrawField();
        void DrawPassabilityField();    // For debug purposes.

        // Access to tiles via 2d coordinates (y,x)
        Tile& operator()(int height, int width);

        // For debug - draws field and pauses.
        void DebugDraw(int y, int x);
};

#endif // FIELD_INCLUDED

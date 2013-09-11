#ifndef TILE_H
#define TILE_H

#include <string>
#include <cassert>

#include "globals.h"

class Tile
{
    private:
    protected:
        int m_tileID;
        std::string m_TileChar;
        bool m_TilePassability;
        Color m_TileColor;

        Tile(); //Protected default constructor

    public:
        Tile(int TileID);
        Tile(int TileID, std::string TileChar, Color TileColor = WHITE_ON_BLACK);
        ~Tile();

        //Getters
        int GetID() { return m_tileID; }
        const std::string& GetTileChar() { return m_TileChar; }
        bool IsPassable() { return m_TilePassability; }
        Color GetColor() { return m_TileColor;}

        //Setters
        void SetID(int tileID) { m_tileID = tileID; }
        void SetTileChar(std::string TileChar) { m_TileChar = TileChar; }
        void SetTilePassability(bool TilePassability) { m_TilePassability =
                                                           TilePassability; }
        void SetColor(Color newColor) { m_TileColor = newColor; }
};

#endif // TILE_H

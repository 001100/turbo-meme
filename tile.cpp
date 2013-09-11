#include "tile.h"

Tile::Tile() :
    m_tileID(-1),
    m_TileChar("?"),
    m_TilePassability(false)
{}

Tile::Tile(int TileID) :
    m_tileID(TileID),
    m_TileChar("+"),
    m_TilePassability(true),
    m_TileColor(WHITE_ON_BLACK)
{
    //ctor
}

Tile::Tile(int TileID, std::string TileChar, Color TileColor) :
    m_tileID(TileID),
    m_TileChar(TileChar),
    m_TilePassability(true),
    m_TileColor(TileColor)
{

}

Tile::~Tile()
{
    //dtor
}

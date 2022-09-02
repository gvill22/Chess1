
#include "ChessPiece.hpp"


ChessPiece::ChessPiece(std::string i, std::string c, std::pair<int,int> p)
{
    icon = i;
    color = c;
    position = p;
}

void ChessPiece::setName( std::string i)
{ 
    icon = i; 
}

std::string ChessPiece::getName() const 
{
    return icon; 
}


void ChessPiece::setColor( std::string c)
{
    color = c; 
}

std::string ChessPiece::getColor() const 
{
   return color; 
}

void ChessPiece::setPosition( std::pair<int,int> p )
{
    position = p; 
}

std::pair<int,int> ChessPiece::getPosition()
{
    return position; 
}


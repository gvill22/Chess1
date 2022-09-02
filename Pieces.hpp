#ifndef _PIECES_HPP_
#define _PIECES_HPP_

#include "ChessPiece.hpp"

class Pawn : public ChessPiece
{

public:
    
    Pawn(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};

class Bishop : public ChessPiece
{

public:
    
    Bishop(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};


class Knight : public ChessPiece
{

public:
    
    Knight(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};


class Rook : public ChessPiece
{

public:
    
    Rook(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};


class Queen : public ChessPiece
{

public:
    
    Queen(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};

class King : public ChessPiece
{

public:
    
    King(std::string i, std::string c, std::pair<int,int> p) : ChessPiece(i,c,p) {};

    std::vector<std::pair<int,int>> generateMoves();

};



#endif
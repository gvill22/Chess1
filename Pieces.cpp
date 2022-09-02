#include "Pieces.hpp"


std::vector<std::pair<int,int>> Pawn::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> pawnMoves;
    return pawnMoves;
}


std::vector<std::pair<int,int>> Bishop::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> bishopMoves;
    return bishopMoves;
}


std::vector<std::pair<int,int>> Knight::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();

    std::vector<std::pair<int,int>> knightMoves;
    return knightMoves;
}


std::vector<std::pair<int,int>> Rook::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> rookMoves;
    return rookMoves;
}


std::vector<std::pair<int,int>> Queen::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> queenMoves;
    return queenMoves;
}


std::vector<std::pair<int,int>> King::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> queenMoves;
    return queenMoves;
}
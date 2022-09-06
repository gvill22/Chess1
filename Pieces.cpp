#include "Pieces.hpp"

// I should probably add some out of bounds checking here
// Then the board can do validation for the attacks and stuff like that
std::vector<std::pair<int,int>> Pawn::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> pawnMoves;
    
    if(this->firstMove && this->getColor() == "b"){
        pawnMoves.push_back(std::make_pair(currentP.first+2, currentP.second));
    }
    else if(this->firstMove && this->getColor() == "w"){
        pawnMoves.push_back(std::make_pair(currentP.first-2, currentP.second));
    }

    if(this->getColor() == "b")
    {
        // Normal forward move
        pawnMoves.push_back(std::make_pair(currentP.first+1, currentP.second));

        // Attack diagonally
        pawnMoves.push_back(std::make_pair(currentP.first+1, currentP.second+1));
        pawnMoves.push_back(std::make_pair(currentP.first+1, currentP.second-1));
    }
    else if(this->getColor() == "w")
    {
        // Normal forward move
        pawnMoves.push_back(std::make_pair(currentP.first-1, currentP.second));
        
        // Attack diagonally
        pawnMoves.push_back(std::make_pair(currentP.first-1, currentP.second+1));
        pawnMoves.push_back(std::make_pair(currentP.first-1, currentP.second-1));
    }

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

    knightMoves.push_back(std::make_pair(currentP.first-2, currentP.second+1));
    knightMoves.push_back(std::make_pair(currentP.first-2, currentP.second-1));

    knightMoves.push_back(std::make_pair(currentP.first+2, currentP.second+1));
    knightMoves.push_back(std::make_pair(currentP.first+2, currentP.second-1));

    knightMoves.push_back(std::make_pair(currentP.first+1, currentP.second-2));
    knightMoves.push_back(std::make_pair(currentP.first-1, currentP.second-2));

    knightMoves.push_back(std::make_pair(currentP.first+1, currentP.second+2));
    knightMoves.push_back(std::make_pair(currentP.first-1, currentP.second+2));

    return knightMoves;
}


std::vector<std::pair<int,int>> Rook::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> rookMoves;

    // the piece is @ bottom of board
    if(currentP.first == 7) 
    {
        //the piece can only move upwards
        int nextRow = 6;
        while(nextRow > -1)
        {
            std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
            rookMoves.push_back(nextMove);
            nextRow--;
        }
    }
    // the piece is @ top of board
    else if(currentP.first == 0)
    {
        //the piece can only move downwards
        int nextRow = 1;
        while(nextRow < 8)
        {
            std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
            rookMoves.push_back(nextMove);
            nextRow++;
        }
    }

    else
    {
        //this piece is free to move up and down
        int nextRow = currentP.first -1; // going up first
        while(nextRow > -1)
        {
            std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
            rookMoves.push_back(nextMove);
            nextRow--;
        }
        nextRow = currentP.first +1; // going down now
        while(nextRow < 8)
        {
            std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
            rookMoves.push_back(nextMove);
            nextRow++;
        }        
    }


    // the piece is @ the right side of board
    if(currentP.second == 7)
    {
        //this piece can only move to the left
        int nextColumn = 6;
        while(nextColumn > -1)
        {
            std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
            rookMoves.push_back(nextMove);
            nextColumn--;   
        }

    }
    // the piece is @ the left side of board
    else if(currentP.second == 0)
    {
        //this piece can only move to right
        int nextColumn = 1;
        while(nextColumn < 8)
        {
            std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
            rookMoves.push_back(nextMove);
            nextColumn++;   
        }
    }
    else
    {
        //this piece is free to move left and right
        int nextColumn = currentP.second-1; // let's go left first
        while(nextColumn > -1)
        {
            std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
            rookMoves.push_back(nextMove);
            nextColumn--;
        }
        nextColumn = currentP.second+1; // now adding all of the moves where we can go right
        while(nextColumn < 8)
        {
            std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
            rookMoves.push_back(nextMove);
            nextColumn++;           
        }
    }


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
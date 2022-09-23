#include "Pieces.hpp"
#include <algorithm>

// this method will remove any of the moves that are out of bounds
// for a given piece
void validateMoves(std::vector<std::pair<int,int>> &moveList)
{
    auto itBegin = std::remove_if(moveList.begin(), moveList.end(),
        [](std::pair<int,int> value)
        {
            if(value.first > 7 || value.first < 0)
            {
                return true;
            }
            if(value.second > 7 || value.second < 0)
            {
                return true;
            }

            return false;
        }
    );
    moveList.erase(itBegin,moveList.end());
}

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

    auto address = &pawnMoves;
    validateMoves(*address);
    return pawnMoves;
}


std::vector<std::pair<int,int>> Bishop::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> bishopMoves;


    // Diagonally down and to the right
    int nextRow = currentP.first +1;
    int nextColumn = currentP.second +1;
    while(nextRow < 8 && nextColumn < 8)
    {
        std::pair<int,int> nextMove = std::pair<int,int>(nextRow,nextColumn);
        bishopMoves.push_back(nextMove);
        nextRow++;
        nextColumn++;            
    }

    // diagonally up and to the left
    nextRow = currentP.first -1;
    nextColumn = currentP.second -1;
    while(nextRow > -1 && nextColumn > -1)
    {
        std::pair<int,int> nextMove = std::pair<int,int>(nextRow,nextColumn);
        bishopMoves.push_back(nextMove);
        nextRow--;
        nextColumn--;            
    }        
    
    // diagonally up and to the right
    nextRow = currentP.first -1;
    nextColumn = currentP.second +1;
    while(nextRow > -1 && nextColumn < 8)
    {
        std::pair<int,int> nextMove = std::pair<int,int>(nextRow,nextColumn);
        bishopMoves.push_back(nextMove);
        nextRow--;
        nextColumn++;            
    }        
    
    // diagonally down and to the left
    nextRow = currentP.first +1;
    nextColumn = currentP.second -1;
    while(nextRow < 8 && nextColumn > -1)
    {
        std::pair<int,int> nextMove = std::pair<int,int>(nextRow,nextColumn);
        bishopMoves.push_back(nextMove);
        nextRow++;
        nextColumn--;            
    }        
    
    auto address = &bishopMoves;
    validateMoves(*address);
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

    auto address = &knightMoves;
    validateMoves(*address);
    return knightMoves;
}


std::vector<std::pair<int,int>> Rook::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> rookMoves;

  
    // going up first
    int nextRow = currentP.first -1;
    while(nextRow > -1)
    {
        std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
        rookMoves.push_back(nextMove);
        nextRow--;
    }

    // going down now
    nextRow = currentP.first +1;
    while(nextRow < 8)
    {
        std::pair<int,int> nextMove = std::make_pair(nextRow,currentP.second);
        rookMoves.push_back(nextMove);
        nextRow++;
    }        


    // let's go left 
    int nextColumn = currentP.second-1;
    while(nextColumn > -1)
    {
        std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
        rookMoves.push_back(nextMove);
        nextColumn--;
    }

    // now go right
    nextColumn = currentP.second+1; 
    while(nextColumn < 8)
    {
        std::pair<int,int> nextMove = std::make_pair(currentP.first,nextColumn);
        rookMoves.push_back(nextMove);
        nextColumn++;           
    }
   

    auto address = &rookMoves;
    validateMoves(*address);
    return rookMoves;
}


std::vector<std::pair<int,int>> Queen::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> queenMoves;


    Rook dummyR = Rook(this->getName(),this->getColor(), getPosition());
    Bishop dummyB = Bishop(this->getName(),this->getColor(),this->getPosition());

    std::vector<std::pair<int,int>> rookMoves = dummyR.generateMoves();
    std::vector<std::pair<int,int>> bishopMoves = dummyB.generateMoves();

    queenMoves.insert(queenMoves.end(), rookMoves.begin(),rookMoves.end());
    queenMoves.insert(queenMoves.end(),bishopMoves.begin(),bishopMoves.end());
    
    auto address = &queenMoves;
    validateMoves(*address);
    return queenMoves;
}


std::vector<std::pair<int,int>> King::generateMoves()
{
    std::pair<int,int> currentP = this->getPosition();
    std::vector<std::pair<int,int>> kingMoves;

    int upOne = currentP.first-1;
    int downOne = currentP.first+1;
    int leftOne = currentP.second -1;
    int rightOne = currentP.second +1;

    std::pair<int,int> moveUp = std::pair<int,int>(upOne, currentP.second);
    std::pair<int,int> moveDown = std::pair<int,int>(downOne, currentP.second);

    kingMoves.push_back(moveUp);
    kingMoves.push_back(moveDown);

    std::pair<int,int> moveLeft = std::pair<int,int>(currentP.first, leftOne);
    std::pair<int,int> moveRight = std::pair<int,int>(currentP.first, rightOne);

    kingMoves.push_back(moveLeft);
    kingMoves.push_back(moveRight);

    std::pair<int,int> moveUpRight = std::pair<int,int>(upOne,rightOne);
    std::pair<int,int> moveUpLeft = std::pair<int,int>(upOne,leftOne);

    kingMoves.push_back(moveUpRight);
    kingMoves.push_back(moveUpLeft);


    std::pair<int,int> moveDownRight = std::pair<int,int>(downOne,rightOne);
    std::pair<int,int> moveDownLeft = std::pair<int,int>(downOne,leftOne);


    kingMoves.push_back(moveDownRight);
    kingMoves.push_back(moveDownLeft);

    auto address = &kingMoves;
    validateMoves(*address);
    return kingMoves;
}
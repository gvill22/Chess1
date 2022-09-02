#include "Board.hpp"
#include "Pieces.hpp"


int main()
{
    Board currentBoard = Board();
    currentBoard.displayBoard();
    std::cout << "\n";
    currentBoard.setupBoard();
    currentBoard.displayBoard();
    
    return 0;
}
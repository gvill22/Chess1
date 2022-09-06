#include "Board.hpp"
#include "Pieces.hpp"


int main()
{
    Board currentBoard = Board();
    currentBoard.displayBoard();
    std::cout << "\n";
    currentBoard.setupBoard();
    currentBoard.displayBoard();
    std::vector<std::pair<int,int>> pmoves = currentBoard.getMoves(std::pair<int,int>(6,1));
    currentBoard.displayMoves(pmoves);
    std::vector<std::pair<int,int>> rmoves = currentBoard.getMoves(std::pair<int,int>(7,7));
    currentBoard.displayMoves(rmoves);
    return 0;
}
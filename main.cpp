#include "Board.hpp"
#include "Pieces.hpp"


int main()
{
    Board currentBoard = Board();
    currentBoard.displayBoard();
    std::cout << "\n";
    currentBoard.setupBoard();
    currentBoard.displayBoard();
    //std::vector<std::pair<int,int>> pmoves = currentBoard.getMoves(std::pair<int,int>(6,1));
    //currentBoard.displayMoves(pmoves);
    //std::vector<std::pair<int,int>> bmoves = currentBoard.getMoves(std::pair<int,int>(7,5));
    //currentBoard.displayMoves(bmoves);

    std::vector<std::pair<int,int>> rmoves = currentBoard.getMoves(std::pair<int,int>(7,7));
    //currentBoard.displayMoves(rmoves);


    // std::vector<std::pair<int,int>> qmoves = currentBoard.getMoves(std::pair<int, int>(7,3));
    // currentBoard.displayMoves(qmoves);

    std::vector<std::pair<int,int>> kmoves = currentBoard.getMoves(std::pair<int,int>(7,4));

    currentBoard.displayMoves(kmoves);
    currentBoard.displayBoard();
    return 0;
}
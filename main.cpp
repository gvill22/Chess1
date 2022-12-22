#include "Board.hpp"
#include "Pieces.hpp"


int main()
{

    Board board = Board();
    board.setupBoard();
    board.displayBoard();
    board.welcomePrompt();
    while(board.isGameOver() == false)
    {
        int userSelection = -1;
        
        std::pair<int,int> selectedPiece;
        std::pair<int,int> move;
        std::vector<std::pair<int,int>> moves;
        std::vector<std::pair<int,int>> *movesPtr = &moves;
        do
        {
            
            selectedPiece = board.readUserSelectedPiece();    
            
            moves = board.getMoves(selectedPiece);
            if( board.getPieceAtCoordinates(selectedPiece)->getName() == "P" )
            {
                moves = board.removeInvalidPawnMoves(*movesPtr, board.getPieceAtCoordinates(selectedPiece));
            }
            board.displayMoves(moves); // this will display the moves for the piece at the coordinates
            board.promptNewPieceOrMakeMove();
            userSelection = board.readUserSelection();
            board.displayBoard();
            
        } while (userSelection == -1);
        
        move = board.readUserMove();
        board.makeMove(selectedPiece, move);

    }
}
#include "Board.hpp"

std::string hBorder()
{
    return "   ---------------------------------------------------------";
}

ChessPiece* Board::Squares::getCurrentPiece() const
{
   return currentPiece; 
}

void Board::Squares::setCurrentPiece(ChessPiece* newPiece)
{
    currentPiece = newPiece;
}


Board::Board()
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++ )
        {
            gameBoard[row][col].setCurrentPiece(nullptr);
        }
    }
}


void Board::setupBoard()
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++ )
        {
            // SETTING UP THE PAWNS
            if(row == 1)
            {
                // It has to be dynamically allocated :(
                ChessPiece* newPiece = new Pawn("P", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 6)
            {
                ChessPiece* newPiece = new Pawn("P", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }

            // SETTING UP ROOKS
            if(row == 0  && col == 0  || row == 0 && col == 7)
            {
                ChessPiece* newPiece = new Rook("R", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 7  && col == 0  || row == 7 && col == 7)
            {
                ChessPiece* newPiece = new Rook("R", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }


            // SETTING UP Knights
            if(row == 0  && col == 1  || row == 0 && col == 6)
            {
                ChessPiece* newPiece = new Knight("Kn", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 7  && col == 1  || row == 7 && col == 6)
            {
                ChessPiece* newPiece = new Knight("Kn", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }            

            // SETTING UP Bishops
            if(row == 0  && col == 2  || row == 0 && col == 5)
            {
                ChessPiece* newPiece = new Bishop("B", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 7  && col == 2  || row == 7 && col == 5)
            {
                ChessPiece* newPiece = new Bishop("B", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }

            //SETTING UP QUEENS
            if(row == 0  && col == 3)
            {
                ChessPiece* newPiece = new Queen("Q", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 7  && col == 3)
            {
                ChessPiece* newPiece = new Queen("Q", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }    

            // SETTING UP KINGS
             if(row == 0  && col == 4)
            {
                ChessPiece* newPiece = new King("Ki", "b", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 7  && col == 4)
            {
                ChessPiece* newPiece = new King("Ki", "w", std::make_pair(row,col));
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }  

        }
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "    " << i << "  ";
    }
    

    std:: cout << "\n" << hBorder() << "\n"; 
    for(int row = 0; row < 8; row++)
    {   
        std::cout << row << "  ";
        for(int col = 0; col < 8; col++ )
        {
            std::cout << "|";

            //ChessPiece* currentPiece = this->gameBoard[row][col].getCurrentPiece();

            if(this->gameBoard[row][col].getCurrentPiece() == nullptr)
            {
                std::cout << "      ";
            }
            else if(this->gameBoard[row][col].getCurrentPiece()->getName().length() > 1)
            {
                std::cout << "  " << this->gameBoard[row][col].getCurrentPiece()->getColor() << this->gameBoard[row][col].getCurrentPiece()->getName() <<" ";
            }
            else
            {
                std::cout << "  " << this->gameBoard[row][col].getCurrentPiece()->getColor() << this->gameBoard[row][col].getCurrentPiece()->getName() << "  ";
            }
            

        }
        std:: cout << "|" << "\n";
        std:: cout << hBorder() << "\n"; 
    }
}

std::vector<std::pair<int,int>> Board::getMoves(std::pair<int,int> coordinates)
{
    std::vector<std::pair<int,int>> moves;
    return moves;
}

void Board::displayMoves(std::vector<std::pair<int,int>> moveList)
{

}

void Board::makeMove(std::pair<int,int> moveHere)
{

}


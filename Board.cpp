#include "Board.hpp"

// this function will create a copy of a vector without moves that have the same color
// piece on that square
std::vector<std::pair<int,int>> Board::removeFriendlyFireMoves(std::vector<std::pair<int,int>> &moveList, ChessPiece* currentP)
{
    std::vector<std::pair<int,int>> valid = std::vector<std::pair<int,int>>();
    
    for(auto it = moveList.begin(); it != moveList.end() ; it++ )
    {
        ChessPiece* piece = this->gameBoard[it->first][it->second].getCurrentPiece();
        if(piece == nullptr)
        {
            valid.push_back(std::make_pair(it->first,it->second));
        }
        if(piece != nullptr && piece->getColor() != currentP->getColor())
        {
            valid.push_back(std::make_pair(it->first,it->second));
        }
    }
    
    return valid;

}





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
                ChessPiece* newPiece = new Pawn("P", "b", std::make_pair(row,col), true);
                this->gameBoard[row][col].setCurrentPiece(newPiece);
            }
            if(row == 6)
            {
                ChessPiece* newPiece = new Pawn("P", "w", std::make_pair(row,col), true);
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
    std::cout << "   ";
    for (int i = 0; i < 8; i++)
    {
        std::cout << "   " << i << "   ";
    }
    

    std:: cout << "\n" << hBorder() << "\n"; 
    for(int row = 0; row < 8; row++)
    {   
        std::cout << row << "  ";
        for(int col = 0; col < 8; col++ )
        {
            std::cout << "|";

            ChessPiece* currentPiece = this->gameBoard[row][col].getCurrentPiece();

            if(currentPiece == nullptr)
            {
                std::cout << "      ";
            }
            else if(currentPiece->getName().length() > 1)
            {
                std::cout << "  " << currentPiece->getColor() << currentPiece->getName() <<" ";
            }
            else
            {
                std::cout << "  " << currentPiece->getColor() << currentPiece->getName() << "  ";
            }
            

        }
        std:: cout << "|" << "\n";
        std:: cout << hBorder() << "\n"; 
    }
}



std::vector<std::pair<int,int>> Board::getMoves(std::pair<int,int> coordinates)
{
    ChessPiece* piece = this->gameBoard[coordinates.first][coordinates.second].getCurrentPiece();
    std::vector<std::pair<int,int>> moves = piece->generateMoves();
    // now we can go and get rid of invalid moves

    std::vector<std::pair<int,int>> betterMoves = removeFriendlyFireMoves(moves,piece);
 
    return betterMoves;
}



void Board::displayMoves(std::vector<std::pair<int,int>> moveList)
{

    if(moveList.empty())
    {
        std::cout <<"\n" << "There are no valid moves for the selected piece\n\n\n";
    }
    else
    {
        std::cout << "\n" << "The list of available moves are: \n";

        for(auto it = moveList.cbegin(); it != moveList.cend(); it++)
        {
            std::cout << "\t" << "row: " << it->first << " col: " << it->second << "\n";
        }
    }

}



void Board::makeMove(std::pair<int,int> moveHere)
{

}


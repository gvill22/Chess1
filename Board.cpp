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

    auto movesAddress = &moves;

    std::vector<std::pair<int,int>> betterMoves = removeFriendlyFireMoves(*movesAddress,piece);
 
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

// this function will create a copy of a vector without moves that have the same color
// piece on that square
std::vector<std::pair<int,int>> Board::removeFriendlyFireMoves(std::vector<std::pair<int,int>> &moveList, const ChessPiece* currentP)
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


const ChessPiece* Board::getPieceAtCoordinates(std::pair<int,int> coordinates)
{
    return this->gameBoard[coordinates.first][coordinates.second].getCurrentPiece();
}



// This function removes the moves that are invalid because pawns can't move diagonally when not capturing
std::vector<std::pair<int,int>> Board::removeInvalidPawnMoves(std::vector<std::pair<int,int>> &moves, const ChessPiece* piece)
{
    std::vector<std::pair<int,int>> betterMoves;

    for(auto it = moves.cbegin(); it != moves.cend(); it++)
    {
        // if the piece is a pawn
        if(piece->getName() == "P")
        {
            // if the pawn is white
            if(piece->getColor() == "w")
            {
                // if the pawn is moving diagonally
                if(it->first < piece->getPosition().first && it->second != piece->getPosition().second)
                {
                    // if the pawn is not capturing a piece
                    if(this->gameBoard[it->first][it->second].getCurrentPiece() == nullptr)
                    {
                        // don't add the move to the list of valid moves
                        continue;
                    }
                }
            }
            // if the pawn is black
            else
            {
                // if the pawn is moving diagonally
                if(it->first > piece->getPosition().first && it->second != piece->getPosition().second)
                {
                    // if the pawn is not capturing a piece
                    if(this->gameBoard[it->first][it->second].getCurrentPiece() == nullptr)
                    {
                        // don't add the move to the list of valid moves
                        continue;
                    }
                }
            }
        }
        betterMoves.push_back(*it);
    }

    return betterMoves;
}



// This function make the move selected by the user, doesn't allow the user to make a friendly fire move
void Board::makeMove(std::pair<int,int> selectedPiece, std::pair<int,int> moveHere)
{
    // get the piece that is currently selected
    ChessPiece* piece = this->gameBoard[selectedPiece.first][selectedPiece.second].getCurrentPiece();
    // get the piece that is currently at the destination
    ChessPiece* destinationPiece = this->gameBoard[moveHere.first][moveHere.second].getCurrentPiece();

    // if the destination is empty, just move the piece
    if(destinationPiece == nullptr)
    {
        this->gameBoard[moveHere.first][moveHere.second].setCurrentPiece(piece);
        this->gameBoard[selectedPiece.first][selectedPiece.second].setCurrentPiece(nullptr);
        piece->setPosition(moveHere);
    }
    // if the destination is occupied by an enemy piece, remove the enemy piece and move the current piece
    else if(destinationPiece->getColor() != piece->getColor())
    {
        this->gameBoard[moveHere.first][moveHere.second].setCurrentPiece(piece);
        this->gameBoard[selectedPiece.first][selectedPiece.second].setCurrentPiece(nullptr);
        piece->setPosition(moveHere);
        delete destinationPiece;
    }
    // if the destination is occupied by a friendly piece, do nothing
    else
    {
        std::cout << "You cannot move to a square occupied by a friendly piece\n";
    }
    
}



std::pair<std::string, std::string> Board::getPieceNameAndColor(std::pair<int,int> coordinates)
{
    std::string pieceName;
    std::string pieceColor;

    pieceName = this->gameBoard[coordinates.first][coordinates.second].getCurrentPiece()->getName();
    pieceColor = this->gameBoard[coordinates.first][coordinates.second].getCurrentPiece()->getColor();

    return std::make_pair(pieceName, pieceColor);
}

void Board::welcomePrompt()
{
    std::cout << "Welcome to Chess!\n";
}


void Board::promptNewPieceOrMakeMove()
{
    std::cout << "Please enter 1 to select a move or enter -1 to select a new piece: ";
}



std::pair<int,int> Board::readUserSelectedPiece()
{
    std::pair<int,int> coordinates;
    std::cout << "Please enter the row and column of the piece you want to move: ";
    std::cin >> coordinates.first >> coordinates.second;
    return coordinates;
}

int Board::readUserSelection()
{
    int selection;
    std::cin >> selection;
    return selection;
}




std::pair<int,int> Board::readUserMove()
{
    std::pair<int,int> coordinates;
    std::cout << "Please enter the row and column of the square you want to move to: ";
    std::cin >> coordinates.first >> coordinates.second;
    return coordinates;
}


bool Board::isGameOver()
{
    // check if the king is dead

    // check if the king is in checkmate

    // check if the king is in stalemate
    return false;
}
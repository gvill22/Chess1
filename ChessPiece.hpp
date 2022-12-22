#ifndef _CHESSPIECE_HPP_
#define _CHESSPIECE_HPP_

#include <string>
#include <utility>
#include <vector>

// Abstract base class that every chess piece will inherit from this parent class
// is meant purely to be inherited from and to leverager polymorphism
// so that we can treat any more specific chass piece the same


class ChessPiece{

private:
    std::string icon;
    std::string color;
    std::pair<int,int> position;


public:
    // So far it seems the only thing that is different between the different
    // classes of chessPieces is that they generate different moves.
    ChessPiece(std::string i, std::string c, std::pair<int,int> p);
    
    void setName( std::string i);

    std::string getName() const;

    void setColor( std::string c);
    std::string getColor() const;

    void setPosition( std::pair<int,int> p );

    std::pair<int,int> getPosition() const;

    virtual std::vector<std::pair<int,int>> generateMoves() = 0;

};



#endif
#ifndef PIECE_H
#define PIECE_H

#include "Drawable.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Square;

class Piece : public Drawable {
protected:
    bool hasMoved;
    Square* square;
    int value;  // Value of the piece
    std::string name;
    int color; // black = 0 white = 1

public:
    Piece(Square* startingSquare, int val);
    virtual ~Piece();

    virtual bool isValidMove(const sf::Vector2f& end) const = 0;
    virtual std::vector<Square*> getValidMoves(Square squares[8][8]) const = 0;

    // void move(const sf::Vector2f& newPosition);
    int getValue() const;

    void setSquare(Square* square);

    std::string getName() const;
    int getColor();

    static std::vector<Piece*> whitePieces;
    static std::vector<Piece*> blackPieces;

    void draw(sf::RenderWindow& window) const override;
};

#endif

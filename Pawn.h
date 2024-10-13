#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class Pawn : public Piece {
private:
    static sf::Texture whitePawnTexture;
    static sf::Texture blackPawnTexture;
    bool hasMoved;  // Tracks whether the pawn has moved
    bool isWhite;   // Tracks if the pawn is white or black

public:
    // Static function to load textures (must be called before creating any Pawn objects)
    static void loadTextures();

    // Constructor
    Pawn(Square* startingSquare, bool isWhite);

    // Destructor
    ~Pawn() override;

    // Check if the move is valid for a pawn
    bool isValidMove(const sf::Vector2f& start, const sf::Vector2f& end) const override;

    // Check if it's the pawn's first move
    bool isFirstMove() const;

    // Update the move status of the pawn
    void setHasMoved(bool moved);

    // Check if the pawn is white
    bool isPawnWhite() const;
};

#endif // PAWN_H

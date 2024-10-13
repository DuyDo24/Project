compile:
	g++ -g -Wall -Wextra main.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
clean:

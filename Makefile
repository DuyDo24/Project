compile:
	g++ main.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Pawn.cpp Clickable.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
clean:
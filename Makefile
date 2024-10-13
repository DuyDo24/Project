compile:
	g++ main.cpp Drawable.cpp Piece.cpp Board.cpp Square.cpp Clickable.cpp Knight.cpp Game.cpp Queen.cpp Rook.cpp Bishop.cpp King.cpp Pawn.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
	./main
clean:
	rm -f main *.o

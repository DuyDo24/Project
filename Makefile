compile:
	g++ -std=c++11 main.cpp Drawable.cpp Piece.cpp Board.cpp Square.cpp Clickable.cpp Knight.cpp Game.cpp Queen.cpp Rook.cpp Bishop.cpp King.cpp Pawn.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
	./main
clean:
	rm -f main *.o

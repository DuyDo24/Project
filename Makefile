compile:
	g++ -std=c++11 main.cpp Drawable.cpp Piece.cpp Board.cpp Square.cpp Clickable.cpp Knight.cpp Game.cpp Queen.cpp Rook.cpp Bishop.cpp King.cpp Pawn.cpp Card.cpp Player.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
	./main
testQueen:
	g++ -std=c++11 maintestqueen.cpp Drawable.cpp Piece.cpp Board.cpp Square.cpp Clickable.cpp Knight.cpp Game.cpp Queen.cpp Rook.cpp Bishop.cpp King.cpp Pawn.cpp Card.cpp Player.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o testQueen -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
	./testQueen

testRook:
	g++ -std=c++11 maintestrook.cpp Drawable.cpp Piece.cpp Board.cpp Square.cpp Clickable.cpp Knight.cpp Game.cpp Queen.cpp Rook.cpp Bishop.cpp King.cpp Pawn.cpp Card.cpp Player.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include/ -o testRook -L/opt/homebrew/Cellar/sfml/2.6.1/lib/ -lsfml-graphics -lsfml-window -lsfml-system
	./testRook

test: testQueen testRook


clean:
	rm -f main *.o

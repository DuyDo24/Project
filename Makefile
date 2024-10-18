compile:
	g++ main.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

testCards:
	g++ cardTesting.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o cardTesting-app -lsfml-graphics -lsfml-window -lsfml-system
	./cardTesting-app

testPlayers:
	g++ playerTesting.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o playerTesting-app -lsfml-graphics -lsfml-window -lsfml-system
	./playerTesting-app

testRook:
	g++ rookTesting.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o rookTesting-app -lsfml-graphics -lsfml-window -lsfml-system
	./rookTesting-app

testQueen:
	g++ queenTesting.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o queenTesting-app -lsfml-graphics -lsfml-window -lsfml-system
	./queenTesting-app

test: testCards testPlayers testRook testQueen

clean:
	rm -f main *.o

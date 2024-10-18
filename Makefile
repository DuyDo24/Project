compile:
	g++ main.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app

testCards:
	g++ cardTesting.cpp Card.cpp Player.cpp Square.cpp Board.cpp Drawable.cpp Piece.cpp Clickable.cpp Pawn.cpp Knight.cpp Bishop.cpp King.cpp Queen.cpp Rook.cpp Game.cpp -o cardTesting-app -lsfml-graphics -lsfml-window -lsfml-system
	./cardTesting-app

test: testCards

clean:
	rm -f main *.o

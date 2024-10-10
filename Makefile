compile:
	g++ main.cpp Square.cpp Board.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
clean:
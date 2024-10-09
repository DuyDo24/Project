compile:
	g++ -c main.cpp
	g++ -c Board.cpp
	g++ -c Square.cpp
	g++ main.o Board.o Square.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
clean:
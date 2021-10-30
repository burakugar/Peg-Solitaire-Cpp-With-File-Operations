all: compile run

compile:
	g++ -I ./include/ -o ./bin/hw2 -std=c++11 ./src/main.cpp ./src/checking_functions.cpp
run:
	./bin/hw2
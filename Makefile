all: stairs

stairs: main.cpp
	g++ -std=c++11 -Wall -Wextra -pedantic -o stairs main.cpp

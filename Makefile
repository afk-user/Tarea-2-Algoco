main: brute dynamic

brute: bruteforce.cpp costos.hpp costos/*.txt
	g++ -Wall -o bruteforce bruteforce.cpp -g

dynamic: dynamic.cpp costos.hpp costos/*.txt
	g++ -Wall -o dynamic dynamic.cpp -g
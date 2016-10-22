Book.o : Book.cpp Book.hpp
	g++ -c -O Book.cpp

UseBookClass.o : UseBookClass.cpp Book.hpp
	g++ -c -O UseBookClass.cpp

UseBookClass : Book.o UseBookClass.o
	clang++ -O -o UseBookClass Book.o UseBookClass.o

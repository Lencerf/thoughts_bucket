main: main.o DoubleVector.o
	clang++ -o main main.o DoubleVector.o

main.o: main.cpp DoubleVector.h
	clang++ -c -O main.cpp

DoubleVector.o: DoubleVector.cpp DoubleVector.h
	clang++ -c -O DoubleVector.cpp
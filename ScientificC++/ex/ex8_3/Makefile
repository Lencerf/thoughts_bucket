main: main.o ComplexNumber.o
	clang++ -O -o main main.o ComplexNumber.o

ComplexNumber.o: ComplexNumber.cpp ComplexNumber.h
	clang++ -c -O ComplexNumber.cpp

main.o: main.cpp ComplexNumber.h
	clang++ -c -O main.cpp
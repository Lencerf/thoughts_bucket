ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
	clang++ -c -O ComplexNumber.cpp

main.o : main.cpp ComplexNumber.hpp
	clang++ -c -O main.cpp

main : main.o ComplexNumber.o
	clang++ -O -o main main.o ComplexNumber.o

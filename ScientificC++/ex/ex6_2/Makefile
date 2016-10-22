matrix2.o : matrix2.cpp matrix2.hpp
	clang++ -c -O matrix2.cpp

main.o : main.cpp matrix2.hpp
	clang++ -c -O main.cpp

main : main.o matrix2.o
	clang++ -O -o main main.o matrix2.o

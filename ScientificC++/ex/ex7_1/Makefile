student.o : student.cpp student.hpp
	clang++ -c -O student.cpp

graduate.o : graduate.cpp graduate.hpp student.hpp
	clang++ -c -O graduate.cpp

phd.o : phd.cpp phd.hpp graduate.hpp student.hpp
	clang++ -c -O phd.cpp

main.o : main.cpp phd.hpp
	clang++ -c -O main.cpp

main : main.o phd.o graduate.o student.o
	clang++ -O -o main main.o phd.o graduate.o student.o

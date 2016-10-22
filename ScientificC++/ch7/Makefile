Book.o : Book.cpp Book.hpp
	g++ -c -O Book.cpp

Ebook.o : Ebook.cpp Ebook.hpp Book.hpp
	clang++ -c -O Ebook.cpp

main.o : main.cpp Ebook.hpp Book.hpp
	clang++ -c -O main.cpp

main : main.o Ebook.o Book.o
	g++ -O -o main main.o Ebook.o Book.o

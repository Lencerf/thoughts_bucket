main: main.o ForwardEulerSolver.o AbstractOdeSolver.o RKSolver.o
	clang++ -O -o main main.o ForwardEulerSolver.o AbstractOdeSolver.o RKSolver.o

AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	clang++ -c -O AbstractOdeSolver.cpp

ForwardEulerSolver.o: ForwardEulerSolver.cpp ForwardEulerSolver.hpp AbstractOdeSolver.hpp
	clang++ -c -O ForwardEulerSolver.cpp

RKSolver.o: RKSolver.cpp RKSolver.hpp AbstractOdeSolver.hpp
	clang++ -c -O RKSolver.cpp

main.o: main.cpp ForwardEulerSolver.hpp AbstractOdeSolver.hpp RKSolver.hpp
	clang++ -c -O main.cpp
main: main.cpp Vector.o Matrix.o LinearSystem.o \
	SecondOrderOde.o FiniteDifferenceGrid.o BoundaryConditions.o BvpOde.o
	clang++ -Os -o main main.cpp Vector.o Matrix.o LinearSystem.o SecondOrderOde.o FiniteDifferenceGrid.o BoundaryConditions.o BvpOde.o
Vector.o: Vector.cpp Vector.hpp
	clang++ -c Vector.cpp -Os

Matrix.o: Matrix.cpp Matrix.hpp
	clang++ -c Matrix.cpp -Os

LinearSystem.o: LinearSystem.cpp LinearSystem.hpp Matrix.hpp Vector.hpp
	clang++ -c LinearSystem.cpp -Os

SecondOrderOde.o: SecondOrderOde.cpp SecondOrderOde.hpp
	clang++ -c SecondOrderOde.cpp -Os

FiniteDifferenceGrid.o: FiniteDifferenceGrid.cpp FiniteDifferenceGrid.hpp
	clang++ -c FiniteDifferenceGrid.cpp -Os

BoundaryConditions.o: BoundaryConditions.cpp BoundaryConditions.hpp
	clang++ -c BoundaryConditions.cpp -Os

BvpOde.o: BvpOde.cpp BvpOde.hpp
	clang++ -c BvpOde.cpp -Os

clean:
	rm main
	rm *.o
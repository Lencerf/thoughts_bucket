//
//  LinearSystem.cpp
//  BvpOde
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include <iostream>
#include "LinearSystem.hpp"
#include <cassert>
#include <cmath>

LinearSystem::LinearSystem(Matrix& coeffMatrix, Vector& rhs) {
    assert(coeffMatrix.getNumRow() == rhs.getSize());
    mp_CoefficientMatrix = new Matrix(coeffMatrix);
    mp_Rhs = new Vector(rhs);
    mp_result = new Vector(coeffMatrix.getNumColumn());
}

LinearSystem::~LinearSystem() {
    delete mp_CoefficientMatrix;
    delete mp_Rhs;
    delete mp_result;
}

void LinearSystem::TrivalSolve() {
    assert(mp_CoefficientMatrix->IsSquaredMatrix());
    
    const double detA = mp_CoefficientMatrix->det();
    const double size = mp_Rhs->getSize();
    assert(fabs(detA) >= 1E-6);
    for (int i = 0; i < size; i++) {
        Matrix matrixi(*mp_CoefficientMatrix);
        for (int j = 0; j < size; j++) {
            matrixi.AtIndex(j, i) = mp_Rhs->AtIndex(j); //pay attention to the order of j and i
        }
        //std::cout << "Matrix " << i << " is\n" << matrixi;
        (*mp_result)[i] = matrixi.det() / detA;
        std::cout << "result[" << i << "] = " << (*mp_result)[i] << std::endl;
    }
}

void swap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}

void LinearSystem::SolveGaussianElimination() {
    assert(mp_CoefficientMatrix->IsSquaredMatrix());
    
    const int size = mp_CoefficientMatrix->getNumRow();
    
    // generate the upper triangular matrix U and vector bPrime
    Matrix U(*mp_CoefficientMatrix);
    Vector bPrime(*mp_Rhs);
    for (int i = 0; i < size; i++) {
        // check if pivoting is needed
        if (U.AtIndex(i, i) == 0) {
            std::cout << i << "th need pivoting.\n";
            int j = i;
            do {
                j++;
            } while (j < size && fabs(U.AtIndex(j, i)) <= 1E-6);
            // exchange ith and jth
            for (int k = i; k < size; k++) {
                swap(U.AtIndex(i, k), U.AtIndex(j, k));
            }
            swap(bPrime.AtIndex(i), bPrime.AtIndex(j));
        }
        // Gaussian Elimination
        for (int i2 = i + 1; i2 < size; i2++) {
            const double m = U.AtIndex(i2, i) / U.AtIndex(i, i);
            bPrime.AtIndex(i2) -= m * bPrime.AtIndex(i);
            for (int j2 = i; j2 < size; j2++) {
                U.AtIndex(i2, j2) -= m * U.AtIndex(i, j2);
            }
        }
    }
    std::cout << U;
    //Solve the new equation
    for (int i = size - 1; i >= 0; i--) {
        double temp = 0.0;
        for (int j = i + 1; j < size; j++) {
            temp += U.AtIndex(i, j) * mp_result->AtIndex(j);
        }
        mp_result->AtIndex(i) = (bPrime.AtIndex(i) - temp) / U.AtIndex(i, i);
    }
    
}

Vector* LinearSystem::getResult() const {
    return mp_result;
}
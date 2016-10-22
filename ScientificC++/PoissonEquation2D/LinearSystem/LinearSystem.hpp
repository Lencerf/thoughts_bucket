//
//  LinearSystem.hpp
//  BvpOde
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef LinearSystem_hpp
#define LinearSystem_hpp

#include <stdio.h>
#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem {
private:
    Matrix* mp_CoefficientMatrix;
    Vector* mp_Rhs;
    Vector* mp_result;
    
public:
    LinearSystem(Matrix& coeffMatrix, Vector& rhs);
    ~LinearSystem();
    void TrivalSolve();
    void SolveGaussianElimination();
    Vector* getResult() const;
};


#endif /* LinearSystem_hpp */

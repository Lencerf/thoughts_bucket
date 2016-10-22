//
//  PoissonEquation2DSolve.hpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef PoissonEquation2DSolve_hpp
#define PoissonEquation2DSolve_hpp

#include <stdio.h>

#include "PoissonEquation2D.hpp"
#include "BoundaryConditions2D.hpp"
#include "FiniteDifferenceGrid2D.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

class PoissonEquation2DSolve {
private:
    PoissonEquation2D* mp_Eq;
    BoundaryConditions2D* mp_Bc;
    FiniteDifferenceGrid2D* mp_Grid;
    Matrix* mp_lhsMatrix;
    Vector* mp_result;
    Vector* mp_rhs;
    LinearSystem* mp_LinearSystem;
    PoissonEquation2DSolve(const PoissonEquation2DSolve& other){}
    
public:
    PoissonEquation2DSolve(PoissonEquation2D* eq, BoundaryConditions2D* Bc,
                           int numNodesX, int numNodesY);
    ~PoissonEquation2DSolve();
    void Solve();
};

#endif /* PoissonEquation2DSolve_hpp */

//
//  PoissonEquation2DSolve.cpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "PoissonEquation2DSolve.hpp"

PoissonEquation2DSolve::PoissonEquation2DSolve(PoissonEquation2D* eq,
                                               BoundaryConditions2D* Bc,
                                               int numNodesX, int numNodesY):
mp_Eq(eq), mp_Bc(Bc) {
    
}

~PoissonEquation2DSolve();
void Solve();
};
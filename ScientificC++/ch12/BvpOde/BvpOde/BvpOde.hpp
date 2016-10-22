//
//  BvpOde.hpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef BvpOde_hpp
#define BvpOde_hpp

#include <stdio.h>

#include "SecondOrderOde.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "BoundaryConditions.hpp"
#include "LinearSystem.hpp"

class BvpOde {
private:
    BvpOde(const BvpOde& otherBvpOde) {}
    
    int mNumNodes;
    SecondOrderOde* mp_Ode;
    BoundaryConditions* mp_Bcs;
    FiniteDifferenceGrid* mp_Grid;
    Vector* mp_SolveVec;
    Vector* mp_RhsVec;
    Matrix* mp_LhsMat;
    LinearSystem* mp_LinearSystem;
public:
    BvpOde(SecondOrderOde* p_Ode, BoundaryConditions* p_Bcs, int numNodes);
    ~BvpOde();
    void SolveOde();
    void WriteSolutionFile(std::string filename);
};

#endif /* BvpOde_hpp */

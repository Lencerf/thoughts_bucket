//
//  BoundaryConditions2D.hpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef BoundaryConditions2D_hpp
#define BoundaryConditions2D_hpp

#include <stdio.h>

class BoundaryConditions2D {
private:
    int mLeftBcType;
    // 0 stand for Dirichlet Bc, 1 stand for x Neumann Bc, 2 stand for y Neumann Bc
    double (*mp_LeftBc)(double y);
    
    int mRightBcType;
    double (*mp_RightBc)(double y);
    
    int mTopBcType;
    double (*mp_TopBc)(double x);
    
    int mBottomBcType;
    double (*mp_BottomBc)(double x);
    
public:
    void SetLeftDirichletBc(double (*p_LeftBc)(double));
    void SetLeftXNeumannBc(double (*p_LeftBc)(double));
    void SetLeftYNeumannBc(double (*p_LeftBc)(double));
    void SetRightDirichletBc(double (*p_RightBc)(double));
    void SetRightXNeumannBc(double (*p_RightBc)(double));
    void SetRightYNeumannBc(double (*p_RightBc)(double));
    void SetTopDirichletBc(double (*p_TopBc)(double));
    void SetTopXNeumannBc(double (*p_TopBc)(double));
    void SetTopYNeumannBc(double (*p_TopBc)(double));
    void SetBottomDirichletBc(double (*p_BottomBc)(double));
    void SetBottomXNeumannBc(double (*p_BottomBc)(double));
    void SetBottomYNeumannBc(double (*p_BottomBc)(double));
};

#endif /* BoundaryConditions2D_hpp */

//
//  BoundaryConditions2D.cpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "BoundaryConditions2D.hpp"

void BoundaryConditions2D::SetLeftDirichletBc(double (*p_LeftBc)(double)) {
    mp_LeftBc = p_LeftBc;
    mLeftBcType = 0;
}

void BoundaryConditions2D::SetLeftXNeumannBc(double (*p_LeftBc)(double)) {
    mp_LeftBc = p_LeftBc;
    mLeftBcType = 1;
}

void BoundaryConditions2D::SetLeftYNeumannBc(double (*p_LeftBc)(double)) {
    mp_LeftBc = p_LeftBc;
    mLeftBcType = 2;
}

void BoundaryConditions2D::SetRightDirichletBc(double (*p_RightBc)(double)) {
    mp_RightBc = p_RightBc;
    mRightBcType = 0;
}

void BoundaryConditions2D::SetRightXNeumannBc(double (*p_RightBc)(double)) {
    mp_RightBc = p_RightBc;
    mRightBcType = 1;
}

void BoundaryConditions2D::SetRightYNeumannBc(double (*p_RightBc)(double)) {
    mp_RightBc = p_RightBc;
    mRightBcType = 2;
}

void BoundaryConditions2D::SetTopDirichletBc(double (*p_TopBc)(double)) {
    mp_TopBc = p_TopBc;
    mTopBcType = 0;
}

void BoundaryConditions2D::SetTopXNeumannBc(double (*p_TopBc)(double)) {
    mp_TopBc = p_TopBc;
    mTopBcType = 1;
}

void BoundaryConditions2D::SetTopYNeumannBc(double (*p_TopBc)(double)) {
    mp_TopBc = p_TopBc;
    mTopBcType = 2;
}

void BoundaryConditions2D::SetBottomDirichletBc(double (*p_BottomBc)(double)) {
    mp_BottomBc = p_BottomBc;
    mBottomBcType = 0;
}

void BoundaryConditions2D::SetBottomXNeumannBc(double (*p_BottomBc)(double)) {
    mp_BottomBc = p_BottomBc;
    mBottomBcType = 1;
}

void BoundaryConditions2D::SetBottomYNeumannBc(double (*p_BottomBc)(double)) {
    mp_BottomBc = p_BottomBc;
    mBottomBcType = 2;
}
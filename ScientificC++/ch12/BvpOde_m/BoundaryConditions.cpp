//
//  BoundaryConditions.cpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "BoundaryConditions.hpp"

BoundaryConditions::BoundaryConditions(): mLhsBcIsDirichlet(false), mLhsBcIsNeumann(false),
mRhsBcIsDirichlet(false), mRhsBcIsNeumann(false) {};

void BoundaryConditions::SetLhsDirichletBc(double lhsValue) {
    mLhsBcIsDirichlet = true;
    mLhsBcIsNeumann = false;
    mLhsBcValue = lhsValue;
}

void BoundaryConditions::SetRhsDirichletBc(double rhsValue) {
    mRhsBcIsDirichlet = true;
    mRhsBcIsNeumann = false;
    mRhsBcValue = rhsValue;
}

void BoundaryConditions::SetLhsNeumannBc(double lhsDerivValue) {
    mLhsBcIsDirichlet = false;
    mLhsBcIsNeumann = true;
    mLhsBcValue = lhsDerivValue;
}

void BoundaryConditions::SetRhsNeumannBc(double rhsDerivValue) {
    mRhsBcIsDirichlet = false;
    mRhsBcIsNeumann = true;
    mRhsBcValue = rhsDerivValue;
}
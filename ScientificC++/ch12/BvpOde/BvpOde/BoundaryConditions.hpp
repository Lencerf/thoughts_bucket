//
//  BoundaryConditions.hpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef BoundaryConditions_hpp
#define BoundaryConditions_hpp

#include <stdio.h>

class BoundaryConditions {
    friend class BvpOde;
private:
    bool mLhsBcIsDirichlet;
    bool mRhsBcIsDirichlet;
    bool mLhsBcIsNeumann;
    bool mRhsBcIsNeumann;
    double mLhsBcValue;
    double mRhsBcValue;
public:
    BoundaryConditions();
    void SetLhsDirichletBc(double lhsValue);
    void SetRhsDirichletBc(double rhsValue);
    void SetLhsNeumannBc(double lhsDerivValue);
    void SetRhsNeumannBc(double rhsDerivValue);
};

#endif /* BoundaryConditions_hpp */

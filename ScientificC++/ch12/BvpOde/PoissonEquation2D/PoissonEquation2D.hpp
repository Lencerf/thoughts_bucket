//
//  PoissonEquation2D.hpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef PoissonEquation2D_hpp
#define PoissonEquation2D_hpp

#include <stdio.h>

class PoissonEquation2D {
private:
    double (*mp_RhsFunc)(double x, double y);
    double mXmin;
    double mXmax;
    double mYmin;
    double mYmax;
    
public:
    PoissonEquation2D(double (*p_RhsFunc)(double, double), double xMin, double xMax,
                      double yMin, double yMax);
};

#endif /* PoissonEquation2D_hpp */

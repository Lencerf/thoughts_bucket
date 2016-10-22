//
//  NIntegrate1D.hpp
//  NIntegrate
//
//  Created by  on 16/1/10.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef NIntegrate1D_hpp
#define NIntegrate1D_hpp

#include <stdio.h>

class NIntegrate1D {
    double (*mp_func)(double x);
    double mXMax;
    double mXMin;
    
public:
    NIntegrate1D(double (*func)(double),double xMin, double xMax)
    :mp_func(func),mXMax(xMax),mXMin(xMin) {}
    double Calculate() const;
};

#endif /* NIntegrate1D_hpp */

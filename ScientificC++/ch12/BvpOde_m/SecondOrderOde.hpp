//
//  SecondOrderOde.hpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef SecondOrderOde_hpp
#define SecondOrderOde_hpp

#include <stdio.h>

class SecondOrderOde {
    friend class BvpOde;
private:
    double mCoeffOfUxx;
    double mCoeffOfUx;
    double mCoeffOfU;
    double mXmin;
    double mXmax;
    
    double (*mp_RhsFunc)(double x);
    
public:
    SecondOrderOde(double coeffUxx, double coeffUx,
                   double coeffU,
                   double (*rightHandside)(double),
                   double xMinimum, double xMaximum);
};

#endif /* SecondOrderOde_hpp */

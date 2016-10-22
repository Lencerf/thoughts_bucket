//
//  SecondOrderOde.cpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "SecondOrderOde.hpp"

SecondOrderOde::SecondOrderOde(double coeffUxx, double coeffUx,
                               double coeffU,
                               double (*rightHandside)(double),
                               double xMinimum, double xMaximum) {
    mCoeffOfUxx = coeffUxx;
    mCoeffOfUx = coeffUx;
    mCoeffOfU = coeffU;
    mXmax = xMaximum;
    mXmin = xMinimum;
    mp_RhsFunc = rightHandside;
}
//
//  NIntegrate1D.cpp
//  NIntegrate
//
//  Created by  on 16/1/10.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "NIntegrate1D.hpp"


double NIntegrate1D:: Calculate() const {
    const double step = (mXMax - mXMin) / 1000;
    double result = 0;
    double xi = 0;
    double xj = mXMin;
    for (int i = 1; i <= 1000; i++) {
        xi = xj;
        xj = mXMin + i * step;
        result += step * ((*mp_func)(xi) + (*mp_func)(xj)) / 2;
    }
    return  result;
}
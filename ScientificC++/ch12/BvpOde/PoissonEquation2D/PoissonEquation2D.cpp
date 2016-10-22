//
//  PoissonEquation2D.cpp
//  BvpOde
//
//  Created by  on 16/1/12.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "PoissonEquation2D.hpp"

PoissonEquation2D::PoissonEquation2D(double (*p_RhsFunc)(double, double),
                                     double xMin, double xMax,
                                     double yMin, double yMax):
mp_RhsFunc(p_RhsFunc),mXmax(xMax),mXmin(xMin),mYmin(yMin),mYmax(yMax) {}
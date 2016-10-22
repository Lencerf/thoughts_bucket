//
//  FiniteDifferenceGrid.hpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef FiniteDifferenceGrid_hpp
#define FiniteDifferenceGrid_hpp

#include <vector>

class FiniteDifferenceGrid {
    friend class BvpOde;
    
private:
    std::vector<double> mNodes;
public:
    FiniteDifferenceGrid(int numNodes, double xMin, double xMax);
    double AtIndex(int n);
};

#endif /* FiniteDifferenceGrid_hpp */

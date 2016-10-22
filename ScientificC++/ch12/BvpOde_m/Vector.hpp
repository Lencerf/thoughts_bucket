//
//  Vector.hpp
//  BvpOde
//
//  Created by on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

class Vector {
private:
    int mDimension;
    double* mData;
public:
    Vector(int size);
    Vector(const Vector& otherVector);
    ~Vector();
    int getSize() const;
    double& AtIndex(int n) const;
    double& operator[](int n);
    Vector& operator=(Vector& otherVector);
};

#endif /* Vector_hpp */

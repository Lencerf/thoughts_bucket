//
//  Vector.cpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "Vector.hpp"

Vector::Vector(int size) {
    mDimension = size;
    mData = new double[size];
    for (int i = 0; i < size; i++) {
        mData[i] = 0.0;
    }
}

Vector::Vector(const Vector& otherVector) {
    mDimension = otherVector.mDimension;
    const int size = otherVector.getSize();
    mData = new double[size];
    for (int i = 0; i < size; i++) {
        mData[i] = otherVector.mData[i];
    }
}

Vector::~Vector() {
    delete[] mData;
}

int Vector::getSize() const {
    return mDimension;
}

double& Vector::AtIndex(int n) const{
    return mData[n];
}

double& Vector::operator[](int n) {
    return mData[n];
}

Vector& Vector::operator=(Vector &otherVector) {
    if (mDimension != otherVector.mDimension) {
        delete[] mData;
        mData = new double[otherVector.mDimension];
        mDimension = otherVector.mDimension;
    }
    for (int i = 0; i < mDimension; i++) {
        mData[i] = otherVector.mData[i];
    }
    return *this;
}
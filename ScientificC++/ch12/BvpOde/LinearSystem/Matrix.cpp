//
//  Matrix.cpp
//  BvpOde
//
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#include "Matrix.hpp"
#include <cassert>
#include <iostream>

Matrix::Matrix(int numRow, int numColumn) {
    mNumColumn = numColumn;
    mNumRow = numRow;
    mData = new double*[numRow];
    for (int i = 0; i < numRow; i++) {
        mData[i] = new double[numColumn];
        for (int j = 0; j < numColumn; j++) {
            mData[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(const Matrix& otherMatrix) {
    mNumRow = otherMatrix.mNumRow;
    mNumColumn = otherMatrix.mNumColumn;
    mData = new double*[mNumRow];
    for (int i = 0; i < mNumRow; i++) {
        mData[i] = new double[mNumColumn];
        for (int j = 0; j < mNumColumn; j++) {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < mNumRow; i++) {
        delete[] mData[i];
    }
    delete[] mData;
}

int Matrix::getNumRow() const {
    return mNumRow;
}

int Matrix::getNumColumn() const {
    return mNumColumn;
}

Matrix Matrix::minorOf(int row, int column) const{
    Matrix minor(mNumRow -1, mNumColumn -1);
    for (int i = 0, i2 = 0; i < mNumRow; i++) {
        if (i != row) {
            for (int j = 0, j2 = 0; j < mNumColumn; j++) {
                if(j != column) {
                    minor.mData[i2][j2] = mData[i][j];
                    j2++;
                }
            }
            i2++;
        }
    }
    return minor;
}

void minor(int size, double** matrix, int x, int y, double** result) {
    for (int i = 0, i2 = 0; i < size; i++) {
        if (i != x) {
            for (int j = 0, j2 = 0; j < size; j++) {
                if(j != y) {
                    result[i2][j2] = matrix[i][j];
                    j2++;
                }
            }
            i2++;
        }
    }
}

double Matrix::det() const {
    assert(mNumRow == mNumColumn);
    const int size = mNumColumn;
    if (size == 1) {
        return mData[0][0];
    } else {
        double det_result = 0;
        for (int i = 0; i < size; i++) {
            if (i%2 == 0) {
                det_result += mData[0][i] * minorOf(0, i).det();
            } else {
                det_result -= mData[0][i] * minorOf(0, i).det();
            }
        }
        return det_result;
    }
}

bool Matrix::IsSquaredMatrix() const {
    return mNumRow == mNumColumn;
}


double& Matrix::AtIndex(int row, int column) {
    return mData[row][column];
}

double* Matrix::operator[](int indexOfRow) const {
    return mData[indexOfRow];
}

Matrix& Matrix::operator=(const Matrix& otherMatrix) {    
    if (mNumColumn == otherMatrix.mNumColumn && mNumRow == otherMatrix.mNumRow) {
        for (int i = 0; i < mNumRow; i++) {
            for (int j = 0; j < mNumColumn; j++) {
                mData[i][j] = otherMatrix.mData[i][j];
            }
        }
    } else {
        //delete self
        for (int i = 0; i < mNumRow; i++) {
            delete[] mData[i];
        }
        delete[] mData;
        //contruct a new one
        mNumRow = otherMatrix.mNumRow;
        mNumColumn = otherMatrix.mNumColumn;
        mData = new double*[mNumRow];
        for (int i = 0; i < mNumRow; i++) {
            mData[i] = new double[mNumColumn];
            for (int j = 0; j < mNumColumn; j++) {
                mData[i][j] = otherMatrix.mData[i][j];
            }
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream& output, const Matrix& matrix) {
    for (int i = 0; i < matrix.mNumRow; i++) {
        for (int j = 0; j < matrix.mNumColumn; j++) {
            output << matrix[i][j] << "\t";
        }
        output << std::endl;
    }
    return output;
}
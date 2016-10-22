//
//  Matrix.hpp
//  BvpOde
//
//  Created by  on 16/1/6.
//  Copyright © 2016年 Lencerf. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <iostream>

class Matrix {
private:
    double** mData;
    int mNumColumn;
    int mNumRow;
    
public:
    Matrix(int numRow, int numColumn);
    Matrix(const Matrix& otherMatrix);
    ~Matrix();
    int getNumRow() const;
    int getNumColumn() const;
    int GetNumberOfRows() const;
    int GetNumberOfColumns() const;
    Matrix minorOf(int row, int column) const;
    double det() const;
    bool IsSquaredMatrix() const;
    double& AtIndex(int row, int column);
    double* operator[](int indexOfRow) const;
    Matrix& operator=(const Matrix& otherMatrix);
    friend std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
    double& operator()(int i, int j);
};

#endif /* Matrix_hpp */

#include <cassert>
#include "DoubleVector.h"

template<unsigned int DIM> 
double& DoubleVector<DIM>::operator[] (int index) {
	assert(index < DIM && index > -1);
	return mData[index];
}

template class DoubleVector<5>;
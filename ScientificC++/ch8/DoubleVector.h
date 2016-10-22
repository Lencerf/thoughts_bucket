#ifndef DOUBLEVECTORDEF
#define DOUBLEVECTORDEF

template<unsigned int DIM> 
class DoubleVector {
private:
	double mData[DIM];
public:
	double& operator[] (int index) ;
};

#endif


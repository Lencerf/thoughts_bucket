//This exercise is problematic!
#include <iostream>
#include <cassert>

template<unsigned int DIM>
class DoubleVector {
private:
	double mData[DIM];
public:
	DoubleVector() {
		for (int i = 0; i < DIM; i++) {
			mData[i] = 0;
		}
	}
	double& operator[] (int index) {
		assert(index < DIM && index > -1);
		assert(mData[index] <= 1+1E-6 && mData[index] >= -1E-6);

		if (mData[index] <= 1.0 && mData[index] >= 0) {
			return mData[index];
		} else if (mData[index] < 0) {
			return mData[index] = 0;
		} else {
			return mData[index] = 1;
		}
	}
};

int main(int argc, char const *argv[]) {
	DoubleVector<4> v;
	v[1] = 2;
	for (int i = 0; i < 4; i++) {
		std::cout << v[i] << "\t";
	}
	std::cout << std::endl;
	return 0;
}
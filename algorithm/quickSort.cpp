#include<iostream>
#include<vector>
#include<vector>
#include<stdlib.h>
#include<algorithm>

template <typename T>
bool isSorted(std::vector<T> &v) {
    if (v.size() < 2) {
        return true;
    } else {
        for (auto i = v.begin() + 1; i != v.end(); ++i) {
            if (*(i-1) <= *i) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
}

template <typename T>
void printVector(std::vector<T> &v) {
    for (auto i:v) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> quickSort(std::vector<T> v) {
    if (v.size() < 2) {
        return v;
    }
    auto pivot = v[v.size() / 2];
    std::vector<T> vLess;
    std::vector<T> vEqual;
    std::vector<T> vLarger;
    for (auto a:v) {
        if (a < pivot) {
            vLess.push_back(a);
        } else if (a > pivot) {
            vLarger.push_back(a);
        } else {
            vEqual.push_back(a);
        }
    }
    auto sortedVLess = quickSort(vLess);
    auto sortedVLarger = quickSort(vLarger);
    std::vector<T> result;
    result.reserve(v.size());
    //http://stackoverflow.com/questions/3177241/what-is-the-best-way-to-concatenate-two-vectors
    result.insert(result.end(), sortedVLess.begin(), sortedVLess.end());
    result.insert(result.end(), vEqual.begin(), vEqual.end());
    result.insert(result.end(), sortedVLarger.begin(), sortedVLarger.end());
    return result;
}

template <typename T> 
void quickSort(std::vector<T> &v, typename std::vector<T>::iterator left, typename std::vector<T>::iterator right) {
    auto i = left;
    auto j = right;
    auto pivot = *(left + (right - left) / 2);
    while (i <= j) {
        while (*i < pivot) {
            ++i;
        }
        while (*j > pivot) {
            --j;
        }
        if (i <= j) {
            std::swap(*i, *j);
            ++i;
            --j;
        }
    }
    if (left < j) {
        quickSort(v, left, j);
    }
    if (i < right) {
        quickSort(v, i, right);
    }
}

// pass by reference
template <typename T>
void quickSortE(std::vector<T> &v) {
    quickSort(v, v.begin(), v.end()-1);
}

int main(int argc, const char* argv[]) {
    std::vector<int> testVector;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 15; ++i) {
        testVector.push_back(rand());
    }
    quickSortE(testVector);
    //printVector(testVector);
    //std::cout << "sorted vector:\n";
    //printVector(sorted);
    if (isSorted(testVector)) {
        std::cout << "test pass\n";
    } else {
        std::wcerr << "test failed!\n";
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<vector>
#include<stdlib.h>

template <typename T>
bool isSorted(std::vector<T> v) {
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
void printVector(std::vector<T> v) {
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

int main(int argc, const char* argv[]) {
    std::vector<int> testVector;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 15; ++i) {
        testVector.push_back(rand());
    }
    //printVector(testVector);
    auto sorted = quickSort(testVector);
    //std::cout << "sorted vector:\n";
    //printVector(sorted);
    if (isSorted(sorted)) {
        std::cout << "test pass\n";
    } else {
        std::wcerr << "test failed!\n";
    }
    return 0;
}

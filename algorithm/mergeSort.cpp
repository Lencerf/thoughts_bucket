#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>

template <typename T>
void printVector(std::vector<T> v) {
    for (auto i:v) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> merge(std::vector<T> v1, std::vector<T> v2) {
    auto i1 = v1.begin();
    auto i2 = v2.begin();
    std::vector<T> mergedV;
    while(i1 != v1.end() && i2 < v2.end()) {
        if(*i1 < *i2) {
            mergedV.push_back(*i1);
            i1 ++;
        } else if (*i1 > *i2) {
            mergedV.push_back(*i2);
            i2 ++;
        } else {
            mergedV.push_back(*i1);
            mergedV.push_back(*i2);
            i1 ++;
            i2 ++;
        }
    }
    for(;i1 != v1.end(); i1++) {
        mergedV.push_back(*i1);
    }
    for(;i2 != v2.end(); i2++) {
        mergedV.push_back(*i2);
    }
    return mergedV;
}

template <typename T>
std::vector<T> mergeSort(std::vector<T> v) {
    if(v.size() < 2) { //very important!
        return v;
    }
    int m = v.size() / 2;
    std::vector<T> v1 (v.begin(), v.begin()+m);
    std::vector<T> v2 (v.begin()+m, v.end());
    auto v1sorted = mergeSort(v1);
    auto v2sorted = mergeSort(v2);
    return merge(v1sorted, v2sorted);
}

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

int main(int argc, const char* argv[]) {
    std::vector<int> testVector;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; ++i) {
        testVector.push_back(rand());
    }
    printVector(testVector);
    auto sorted = mergeSort(testVector);
    std::cout << "sorted vector:\n";
    printVector(sorted);
    if (isSorted(sorted)) {
        std::cout << "test pass\n";
    } else {
        std::wcerr << "test failed!\n";
    }
    return 0;
}

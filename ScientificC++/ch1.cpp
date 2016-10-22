#include "stdio.h"
int main(int argc, char const *argv[]) {
        //int a = 1;
        //std::cout << (a*=2) << " " << (a+=3) << " " << a << std::endl;
    int a = 1;
    int c = (a=a * 2) + (a = a + 3);
    printf("a = %d, c = %d\n", a, c);
    return 0;
}
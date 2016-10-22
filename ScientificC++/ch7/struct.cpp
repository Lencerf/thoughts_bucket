#include <iostream>
using namespace std;

class class1
{
public:
    class1(int a);
    int int_a;          
};

class1::class1 (int a): int_a(a) {
    cout << "construct Test1\n";
}

struct Test1
{
    int i;
    Test1(int a):i(a){cout << "construct Test1\n";}
};

struct Test2
{
    Test1 test1 ;
    Test2(Test1 &t1):test1(t1){cout << "construct Test2\n";}
};

int main(int argc, char const *argv[]) {
    Test1 t1(5) ;
    cout << endl;
    Test2 t2(t1) ;

    class1 c1(5);
    return 0;
}
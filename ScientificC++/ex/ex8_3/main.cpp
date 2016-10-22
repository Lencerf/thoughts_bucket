#include <iostream>
#include <vector>
#include <algorithm>
#include "ComplexNumber.h"

int main(int argc, char const *argv[]) {
   std::vector<ComplexNumber> vTest;
   vTest.push_back(ComplexNumber(1));
   vTest.push_back(ComplexNumber(1, -1));
   std::vector<ComplexNumber>::const_iterator c;
   for (std::vector<ComplexNumber>::iterator i = vTest.begin(); i != vTest.end(); ++i)
   {
      std::cout << *i << "\t";
   }
   std::cout << std::endl;
   return 0;
}
#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
   double mRealPart;
   double mImaginaryPart;
public:
   ComplexNumber();
   ComplexNumber(const ComplexNumber& otherComplexNumber);
   ComplexNumber(double x, double y);
   ComplexNumber(double x);
   double CalculateModulus() const;
   double CalculateArgument() const;
   double GetRealPart() const;
   double GetImaginaryPart() const;
   ComplexNumber CalculatePower(double n) const;
   ComplexNumber CalculateConjugate() const;
   void SetConjugate();
   ComplexNumber& operator=(const ComplexNumber& z);
   ComplexNumber operator-() const;
   ComplexNumber operator+(const ComplexNumber& z) const;
   ComplexNumber operator-(const ComplexNumber& z) const;
   ComplexNumber operator*(const ComplexNumber& z) const;
   ComplexNumber operator/(const double& x) const;
   ComplexNumber operator/(const ComplexNumber& z) const;
   friend std::ostream& operator<<(std::ostream& output, 
                                   const ComplexNumber& z);
   friend double RealPart (ComplexNumber z);
   friend double ImaginaryPart (ComplexNumber z);
};

#endif
//Code from Chapter06.tex line 746 save as ComplexNumber.hpp

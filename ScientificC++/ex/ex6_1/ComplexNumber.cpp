#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
   mRealPart = 0.0;
   mImaginaryPart = 0.0;
}

ComplexNumber::ComplexNumber(const ComplexNumber& otherComplexNumber) {
   mRealPart = otherComplexNumber.mRealPart;
   mImaginaryPart = otherComplexNumber.mImaginaryPart;
}


// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y): mRealPart(x), mImaginaryPart(y) {}

ComplexNumber::ComplexNumber(double x): mRealPart(x), mImaginaryPart(0) {}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
   return sqrt(mRealPart*mRealPart+
               mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
   return atan2(mImaginaryPart, mRealPart);
}

double ComplexNumber::GetRealPart() const {
   return mRealPart;
}

double ComplexNumber::GetImaginaryPart() const {
   return mImaginaryPart;
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
   if (n == 0) {
      return ComplexNumber(1);
   }
   double modulus = CalculateModulus();
   double argument = CalculateArgument();
   double mod_of_result = pow(modulus, n);
   double arg_of_result = argument*n;
   double real_part = mod_of_result*cos(arg_of_result);
   double imag_part = mod_of_result*sin(arg_of_result);
   ComplexNumber z(real_part, imag_part); 
   return z; 
}

ComplexNumber ComplexNumber::CalculateConjugate() const {
   return ComplexNumber(mRealPart, -mImaginaryPart);
}

void ComplexNumber::SetConjugate() {
   mImaginaryPart = - mImaginaryPart;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::
               operator=(const ComplexNumber& z)
{
   mRealPart = z.mRealPart;
   mImaginaryPart = z.mImaginaryPart;
   return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
   ComplexNumber w;
   w.mRealPart = -mRealPart;
   w.mImaginaryPart = -mImaginaryPart;
   return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
              operator+(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart + z.mRealPart;
   w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
   return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
              operator-(const ComplexNumber& z) const
{
   ComplexNumber w;
   w.mRealPart = mRealPart - z.mRealPart;
   w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
   return w;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const {
   const double x = mRealPart * z.mRealPart - mImaginaryPart * z.mImaginaryPart;
   const double y = mRealPart * z.mImaginaryPart + mImaginaryPart * z.mRealPart;
   return ComplexNumber(x,y);
}

ComplexNumber ComplexNumber::operator/(const double& x) const {
   return ComplexNumber(mRealPart / x, mImaginaryPart / x);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& z) const {
   return (*this) * z.CalculateConjugate() / (z.CalculateModulus() * z.CalculateModulus());

}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
   // Format as "(a + bi)" or as "(a - bi)"
   output << "(" << z.mRealPart << " ";
   if (z.mImaginaryPart >= 0.0) {
      output << "+ " << z.mImaginaryPart << "i)";
   }
   else
   {
      // z.mImaginaryPart < 0.0
      // Replace + with minus sign 
      output << "- " << -z.mImaginaryPart << "i)";
   }
   return output;
}

double RealPart (ComplexNumber z) {
   return z.mRealPart;
}

double ImaginaryPart (ComplexNumber z) {
   return z.mRealPart;
}
//Code from Chapter06.tex line 779 save as ComplexNumber.cpp

class matrix2
{
private:
	double element[2][2];
public:
	matrix2();
	matrix2(const matrix2& otherMatrix2);
	matrix2(double a, double b, double c, double d);
	double determinant() const;
	matrix2 inverse() const;
	matrix2& operator= (const matrix2& m2);
	matrix2 operator-() const;
	matrix2 operator+(const matrix2& m2) const;
	matrix2 operator-(const matrix2& m2) const;
	friend std::ostream& operator<<(std::ostream& output, const matrix2& m2);
	matrix2 Multiply(const double x) const;
};
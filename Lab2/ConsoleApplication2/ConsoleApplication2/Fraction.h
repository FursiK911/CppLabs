#pragma once
class Fraction
{
private:
	int numerator;
	int denomerator;
public:
	Fraction(int n1, int n2);
	~Fraction();
	Fraction Fraction::operator+(const Fraction& frac);
	Fraction Fraction::operator-(const Fraction& frac);
	Fraction Fraction::operator*(const Fraction& frac);
	Fraction Fraction::operator/(const Fraction& frac);
	static int Fraction::gcd(int n1, int n2);
	static void printAsFraction(double dec_fraction);
	static void printAsFraction(char* dec_fraction);
	void print();
	void reduce(int gdc, int & tmp_numerator, int & tmp_denumerator);
	static int count;
};


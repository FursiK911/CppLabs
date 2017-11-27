#include "Fraction.h"

#include <iostream>
#include <iomanip> 
#include <sstream>
#include <cmath>
#include <cstdio>

using namespace std;

int Fraction::count = 0;

Fraction::Fraction(int n, int m)
{
	numerator = n;
	denomerator = m;
	count++;
}


Fraction::~Fraction()
{
	count--;
}

Fraction Fraction::operator+(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNomerator;
	all_tmp_deNomerator = denomerator * frac.denomerator;
	all_tmp_numerator = ((all_tmp_deNomerator / frac.denomerator) * (frac.numerator)) + ((all_tmp_deNomerator / denomerator) * (numerator));
	reduce(gcd(all_tmp_numerator, all_tmp_deNomerator), all_tmp_numerator, all_tmp_deNomerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNomerator);
	count++;
	return tmp_frac;
}

Fraction Fraction::operator-(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denomerator * frac.denomerator;
	all_tmp_numerator = ((all_tmp_deNumerator / frac.denomerator) * (frac.numerator)) - ((all_tmp_deNumerator / denomerator) * (numerator));
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	count++;
	return tmp_frac;
}

Fraction Fraction::operator*(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denomerator * frac.denomerator;
	all_tmp_numerator = numerator * frac.numerator;
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	count++;
	return tmp_frac;
}

Fraction Fraction::operator/(const Fraction& frac)
{
	int all_tmp_numerator, all_tmp_deNumerator;
	all_tmp_deNumerator = denomerator * frac.numerator;
	all_tmp_numerator = numerator * frac.denomerator;
	reduce(gcd(all_tmp_numerator, all_tmp_deNumerator), all_tmp_numerator, all_tmp_deNumerator);
	Fraction tmp_frac(all_tmp_numerator, all_tmp_deNumerator);
	count++;
	return tmp_frac;
}

int Fraction::gcd(int a, int b)
{
	int i;
	if (a > b) i = a;
	else i = b;

	for (; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
		{
			return i;
		}
	}
	return 1;
}

void Fraction::printAsFraction(double dec_fraction)
{
	double tmp_upper, tmp_down;
	int tmp_deNumerator = 1, tmp_numerator;
	tmp_down = std::modf(dec_fraction, &tmp_upper);

	stringstream ss;
	ss << tmp_down;
	string str = ss.str();
	int position = str.find(".");
	int count_after = str.size() - 2;
	for (int i(0); i < count_after; i++) tmp_deNumerator *= 10;
	tmp_numerator = (tmp_upper * tmp_deNumerator) + (tmp_down * tmp_deNumerator);

	int gdc = gcd(tmp_numerator, tmp_deNumerator);
	tmp_numerator = tmp_numerator / gdc;
	tmp_deNumerator = tmp_deNumerator / gdc;

	cout << tmp_numerator << "/" << tmp_deNumerator << endl;
}

void Fraction::printAsFraction(char* dec_fraction)
{
	stringstream ss(dec_fraction);
	double decimal_fraction;
	ss >> decimal_fraction;

	double tmp_upper, tmp_down;
	int tmp_deNumerator = 1, tmp_numerator;
	tmp_down = std::modf(decimal_fraction, &tmp_upper);

	ss << tmp_down;
	string str = ss.str();
	int position = str.find(",");
	int count_after = str.size() - 2;
	for (int i(0); i < count_after; i++) tmp_deNumerator *= 10;
	tmp_numerator = (tmp_upper * tmp_deNumerator) + (tmp_down * tmp_deNumerator);

	int gdc = gcd(tmp_numerator, tmp_deNumerator);
	tmp_numerator = tmp_numerator / gdc;
	tmp_deNumerator = tmp_deNumerator / gdc;

	cout << tmp_numerator << "/" << tmp_deNumerator << endl;
}

void Fraction::print()
{
	cout << numerator << "/" << denomerator<<endl;
}

void Fraction::reduce(int gdc, int& tmp_numerator, int& tmp_denumerator)
{
	tmp_numerator = tmp_numerator / gdc;
	tmp_denumerator = tmp_denumerator / gdc;
}


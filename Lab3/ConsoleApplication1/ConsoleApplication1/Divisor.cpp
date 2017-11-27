#include "Divisor.h"
#include <iostream>
#include <fstream>
using namespace std;

Divisor::Divisor()
{
}

Divisor::~Divisor()
{
}

double Divisor::calculate()
{
	double* tmpArr = getArr();
	div = *(tmpArr + 0);
	for (int i = 1; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) == 0)
			return 0.0;
		div /= *(tmpArr + i);
	}

	return div;
}

void Divisor::logToScreen()
{
	std::cout << "Divisor :" << endl;
	double* tmpArr = getArr();
	cout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			cout << *(tmpArr + i);
		else
			cout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			cout << "/";
	}
	cout << " = " << div << endl;
}

void Divisor::logToFile(const std::string & filename)
{
	double* tmpArr = getArr();

	std::fstream fout(filename, std::ios::app);

	fout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			fout << *(tmpArr + i);
		else
			fout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			fout << "/";
	}
	fout << " = " << div << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void Divisor::shuffle()
{
	double* tmpArr = getArr();
	div = 0;
	for (int i = 1; i < getoperandsLenght(); ++i)
	{
		for (int r = 0; r < getoperandsLenght()-i; r++)
		{
			if (tmpArr[r] < 0)
			{
				double temp = tmpArr[r];
				tmpArr[r] = tmpArr[r + 1];
				tmpArr[r + 1] = temp;
			}
		}
	}
}

void Divisor::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		double tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}

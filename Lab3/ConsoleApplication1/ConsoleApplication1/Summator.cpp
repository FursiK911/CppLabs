#include "Summator.h"
#include <iostream>
#include <fstream>
using namespace std;


Summator::Summator()
{
}

Summator::~Summator()
{

}

double Summator::calculate()
{
	double* tmpArr = getArr();
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		sum += *(tmpArr + i);
	}

	return sum;
}

void Summator::logToScreen()
{
	std::cout << "Summator :" << endl;
	double* tmpArr = getArr();
	cout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
			cout << *(tmpArr + i);
		else
			cout << "(" << *(tmpArr + i) << ")";
		if (getoperandsLenght() != i + 1)
			cout << "+";
	}
	cout << "=" << sum << endl;
}

void Summator::logToFile(const std::string & filename)
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
			fout << "+";
	}
	fout << "=" << sum << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void Summator::shuffle()
{
	double* tmpArr = getArr();
	sum = 0;
	for (int i = 1; i < getoperandsLenght(); ++i)
	{
		for (int r = 0; r < getoperandsLenght() - i; r++)
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

void Summator::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		int tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}

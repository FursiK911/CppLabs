#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>
using namespace std;


CustomExpressionEvaluator::CustomExpressionEvaluator()
{
}

CustomExpressionEvaluator::~CustomExpressionEvaluator()
{
}

double CustomExpressionEvaluator::calculate()
{
	double* tmpArr = getArr();
	result = *(tmpArr + 0);
	for (int i = 1; i < getoperandsLenght(); i++)
	{
		if (i % 2 == 0)
		{
			result -= *(tmpArr + i);
		}
		else
		{
			result += *(tmpArr + i);
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen()
{
	std::cout << "CustomExpressionEvaluator :" << endl;
	double* tmpArr = getArr();
	cout << "Expression [" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
		{
			cout << *(tmpArr + i);
		}
		else
		{
			cout << "(" << *(tmpArr + i) << ")";
		}
		if (getoperandsLenght() != i + 1)
		{
			if (i % 2 == 0)
			{
				cout << " + ";
			}
			else
			{
				cout << " - ";
			}
		}
	}
	cout << " = " << result << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string & filename)
{
	double* tmpArr = getArr();

	std::fstream fout(filename, std::ios::app);

	fout << "Expression[" << getoperandsLenght() << "] : ";
	for (int i = 0; i < getoperandsLenght(); i++)
	{
		if (*(tmpArr + i) >= 0)
		{
			fout << *(tmpArr + i);
		}
		else
		{
			fout << "(" << *(tmpArr + i) << ")";
		}
		if (getLenght() != i + 1)
		{
			if (i % 2 == 0)
			{
				fout << " + ";
			}
			else
			{
				fout << " - ";
			}
		}
	}
	fout << " = " << result << endl;
	fout << std::endl << std::endl;
	fout.close();
}

void CustomExpressionEvaluator::shuffle()
{
	double* tmpArr = getArr();

	for (int i = 0; i < getoperandsLenght(); i++)
	{
		for (int j = getoperandsLenght(); j > i; j--)
		{
			if (tmpArr[j - 1] < 0)
			{
				double tmp = tmpArr[j - 1];
				tmpArr[j - 1] = tmpArr[j];
				tmpArr[j] = tmp;
			}
		}
	}
}

void CustomExpressionEvaluator::shuffle(int i, int j)
{
	double* tmpArr = getArr();
	if (*(tmpArr + i) < 0 && *(tmpArr + j) > 0)
	{
		double tmp = tmpArr[j];
		tmpArr[j] = tmpArr[i];
		tmpArr[i] = tmp;
	}
}

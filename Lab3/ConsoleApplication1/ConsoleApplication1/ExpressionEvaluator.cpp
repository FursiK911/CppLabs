#include "ExpressionEvaluator.h"



ExpressionEvaluator::ExpressionEvaluator()
{
	lenght = 20;
	opArr = new double[lenght];
	
	for (int i = 0; i < lenght; i++)
	{
		*(opArr + i) = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(int n)
{
	lenght = n;
	lenghtOperators = n;
	opArr = new double[lenght];

	for (int i = 0; i < lenght; i++)
	{
		*(opArr + i) = 0;
	}
}

ExpressionEvaluator::~ExpressionEvaluator()
{
	delete[] opArr;
}

int ExpressionEvaluator::getLenght()
{
	return lenght;
}

int ExpressionEvaluator::getoperandsLenght()
{
	return lenghtOperators;
}

double* ExpressionEvaluator::getArr()
{
	return opArr;
}

void ExpressionEvaluator::setOperand(int pos, double value)
{
	*(opArr + pos) = value;
	calculateoperandslenght();
}

void ExpressionEvaluator::setOperands(double ops[], int N)
{
	for (int i = 0; i < N; i++)
	{
		*(opArr + i) = ops[i];
	}
	calculateoperandslenght();
}

void ExpressionEvaluator::calculateoperandslenght()
{
	for (int i = 0; i < lenght; i++)
	{
		if (opArr[i] != 0)
		{
			lenghtOperators = i + 1;
		}
	}
}
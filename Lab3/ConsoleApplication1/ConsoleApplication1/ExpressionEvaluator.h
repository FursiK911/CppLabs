#pragma once
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
private:
	int lenght;
	int lenghtOperators;
	double* opArr;
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int n);
	virtual ~ExpressionEvaluator();

	int getLenght();
	int getoperandsLenght();
	double* getArr();
	void setOperand(int pos, double value);
	void setOperands(double ops[], int N);
	void calculateoperandslenght();

	virtual double calculate() = 0;
};


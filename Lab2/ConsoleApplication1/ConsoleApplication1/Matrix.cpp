#include "Matrix.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(int rows, int cols)
{
	mas2d = new double*[rows];
	for (int i = 0; i<cols; i++)
	{
		*(mas2d + i) = new double[cols];
	}
}

Matrix::~Matrix()
{
	for (int i(0); i < n; i++)
	{
		delete[] *(mas2d + i);
	}
}

double Matrix::at(int i, int j) const
{
	return *(*(mas2d+ i) + j);
}

void Matrix::setAt(int i, int j, double value)
{
	*(*(mas2d + i) + j) = value;
}
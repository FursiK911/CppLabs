#include "Vector.h"
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

Vector::Vector()
{
	double* mas1d = new double[lenght];
	initialize();
}

Vector::~Vector()
{
		delete[] mas1d;
}

void Vector::initialize()
{
	std::cout << "Create vector" << std::endl;
	lenght = 25;
	Pi = 3.14;
	mas1d = new double[lenght];
	for (int i = 0; i<lenght; i++)
	{
		*(mas1d + i) = i*sin(Pi*i / 25);
	}
}

void Vector::view()
{
	for (int i = 0; i<lenght; i++)
	{
		cout.width(10);
		cout << *(mas1d + i);
	}
	cout << endl;
}

double Vector::operator[](int index)
{
	if (index < lenght && index >= 0)
		return *(mas1d + index);
	else
		return NULL;
}

Vector& Vector::operator++()
{
	// префиксный оператор делаем свои действия и возвращаем ссылку на себя
	for (int i(0); i < lenght; i++)
	{
		*(mas1d + i) += 1.0;
	}
	return *this;
}

Vector& Vector::operator--()
{
	// префиксный оператор делаем свои действия и возвращаем ссылку на себя
	for (int i(0); i < lenght; i++)
	{
		*(mas1d + i) -= 1.0;
	}
	return *this;
}

const Vector Vector::operator--(int)
{
	Vector oldValue;
	for (int i = 0; i < lenght; i++)
	{
		oldValue.mas1d[i] = this->mas1d[i];
	}

	for (int i = 0; i < lenght; i++)
	{
		mas1d[i] -= 1.0;
	}
	return oldValue;
}

const Vector Vector::operator++(int)
{
	Vector oldValue;
	for (int i = 0; i < lenght; i++)
	{
		oldValue.mas1d[i] = this->mas1d[i];
	}

	for (int i = 0; i < lenght; i++)
	{
		*(mas1d + i) += 1.0;
	}
	return oldValue;
}

Matrix* Vector::processArray()
{
	Matrix* matrix = new Matrix(5, 5);
	cout << "\nView mas2d" << endl;

	//View mas2d
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			matrix->setAt(i, j, *(mas1d + i * 5 + j));
			cout.width(10);
			cout << matrix->at(i, j);
		}
		cout << "\n";
	}

	cout << "\nView Final mas2d" << endl;
	//Sum mas2d
	for (int i = 0; i < 5; ++i)
	{
		matrix->setAt(i, 0, matrix->at(i, 1) + matrix->at(i, 2) + matrix->at(i, 3) + matrix->at(i, 4));
	}
	//View final mas2d
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout.width(10);
			cout << matrix->at(i, j);
		}
		cout << "\n";
	}
	return matrix;
}

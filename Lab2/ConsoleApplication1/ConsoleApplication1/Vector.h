#pragma once
class Matrix;
class Vector
{
private:
	unsigned int lenght;
	double* mas1d;
	void Vector::initialize();
	double Pi;
public:
	Vector();
	~Vector();
	double operator[](int index);
	Vector& operator++();
	Vector& operator--();
	const Vector Vector::operator--(int);
	const Vector Vector::operator++(int);
	void Vector::view();
	Matrix* Vector::processArray();
};


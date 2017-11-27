#pragma once
class Matrix
{
private:
	double** mas2d;
	int n;
public:
	Matrix(int rows, int cols);
	~Matrix();
	double at(int i, int j) const;
	void setAt(int i, int j, double value);
};


#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Vector* v = new Vector();
	cout << (*v)[5] << endl;
	(*v).view();
	Matrix* m = (*v).processArray();
	system("pause");
}
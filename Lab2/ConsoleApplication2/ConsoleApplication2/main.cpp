#include <iostream>
#include "Fraction.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Fraction f1(1, 2), f2(1, 4);
	cout << "���� �����: " << endl;
	f1.print();
	f2.print();
	cout << "������������ ��������: " << endl;
	Fraction::printAsFraction(0.25);
	Fraction::printAsFraction("0.25");
	cout << Fraction::gcd(10,20) << endl;
	cout << "���������� ����������:" << endl;
	Fraction f3 = f1 + f2;
	f3.print();
	Fraction f4 = f1 - f2;
	f4.print();
	Fraction f5 = f1 * f2;
	f5.print();
	Fraction f6 = f1 / f2;
	f6.print();

	cout << "����������: " << Fraction::count << endl;

	system("pause");
}
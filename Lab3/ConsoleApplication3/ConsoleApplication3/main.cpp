#include <iostream>
#include <iomanip>
#include "Shop.h"
#include "Boutique.h"
#include "Pharmacy.h"
#include "ITaxPayment.h"
using namespace std;

//void sort(Shop& x, Shop& y, Shop& z)
//{
//	Shop arr[3];			//������� � ��������� ��������� ������
//	arr[0].setName(x.getName());
//	arr[0].setAdress(x.getAdress());
//	arr[0].setYear(x.getYear());
//	arr[0].setNumber(x.getNumber());
//	arr[0].setTotalProfit(x.getTotalProfit());
//
//	arr[1].setName(y.getName());
//	arr[1].setAdress(y.getAdress());
//	arr[1].setYear(y.getYear());
//	arr[1].setNumber(y.getNumber());
//	arr[1].setTotalProfit(y.getTotalProfit());
//
//	arr[2].setName(z.getName());
//	arr[2].setAdress(z.getAdress());
//	arr[2].setYear(z.getYear());
//	arr[2].setNumber(z.getNumber());
//	arr[2].setTotalProfit(z.getTotalProfit());
//
//	int i;
//	cout << "1.���������� �� �������� ����� �������\n2.���������� �� �������� �������� �������� �������" << endl;
//	cin >> i;
//	switch (i)
//	{
//	case 1:
//		for (int i = 0; i < 2; i++) //���������...
//			for (int j = 2; j > i; j--)
//				if (arr[j - 1].getTotalProfit() < arr[j].getTotalProfit())
//				{
//					int tmp = arr[j - 1].getTotalProfit();
//					arr[j - 1].setTotalProfit(arr[j].getTotalProfit());
//					arr[j].setTotalProfit(tmp);
//				}
//		//������� ���������� ����������
//		cout << setw(23) << arr[0].getName() << setw(23) << arr[1].getName() << setw(23) << arr[2].getName() << endl; 
//		cout << setw(23) << arr[0].getAdress() << setw(23) << arr[1].getAdress() << setw(23) << arr[2].getAdress() << endl;
//		cout << setw(23) << arr[0].getYear(1) << setw(23) << arr[1].getYear(1) << setw(23) << arr[2].getYear(1) << endl;
//		cout << setw(23) << arr[0].getNumber() << setw(23) << arr[1].getNumber() << setw(23) << arr[2].getNumber() << endl;
//		cout << setw(23) << arr[0].getTotalProfit() << setw(23) << arr[1].getTotalProfit() << setw(23) << arr[2].getTotalProfit() << endl;
//		cout << endl;
//		break;
//	case 2:
//		for (int i = 0; i < 2; i++) //���������...
//			for (int j = 2; j > i; j--)
//				if ((arr[j - 1].getTotalProfit()/90) < (arr[j].getTotalProfit()/90))
//				{
//					int tmp = arr[j - 1].getTotalProfit();
//					arr[j - 1].setTotalProfit(arr[j].getTotalProfit());
//					arr[j].setTotalProfit(tmp);
//				}
//		//������� ���������� ����������
//		cout << setw(23) << arr[0].getName() << setw(23) << arr[1].getName() << setw(23) << arr[2].getName() << endl;
//		cout << setw(23) << arr[0].getAdress() << setw(23) << arr[1].getAdress() << setw(23) << arr[2].getAdress() << endl;
//		cout << setw(23) << arr[0].getYear(1) << setw(23) << arr[1].getYear(1) << setw(23) << arr[2].getYear(1) << endl;
//		cout << setw(23) << arr[0].getNumber() << setw(23) << arr[1].getNumber() << setw(23) << arr[2].getNumber() << endl;
//		cout << setw(23) << arr[0].getTotalProfit() << setw(23) << arr[1].getTotalProfit() << setw(23) << arr[2].getTotalProfit() << endl;
//		cout << endl;
//		break;
//	default:
//		break;
//	}
//}

void main()
{
	setlocale(LC_ALL, "Russian");

	string name1 = "�������";
	string adress1 = "���������������_�����,46,������";
	tm year1;
	year1.tm_year = 1998;
	int number1 = 1;
	int totalProfit1 = 0;
	int clientDiscount1 = 8;
	tm work1;
	string type1 = "�������������";

	string name2 = "�������� ������";
	string adress2 = "�����_�����,32,������";
	tm year2;
	year2.tm_year = 1999;
	int number2 = 2;
	int totalProfit2 = 0;
	int clientDiscount2 = 12;
	tm word2;
	string type2 = "�� �������������";

	string name3 = "��� �������";
	string adress3 = "�����_�����,84,������";
	tm year3;
	year3.tm_year = 2000;
	int number3 = 3;
	int totalProfit3 = 0;
	int clientDiscount3 = 3;
	tm word3;
	string type3 = "�������������";

	Shop* shop[3];
	shop[0] = new Pharmacy();
	shop[1] = new Pharmacy();
	shop[2] = new Boutique();
	shop[0]->setName(name1);
	shop[0]->setAdress(adress1);
	shop[0]->setYear(year1);
	shop[0]->setNumber(number1);
	shop[0]->setTotalProfit(totalProfit1);
	shop[0]->setNumberClientDiscount(clientDiscount1);
	shop[0]->setType(type1);

	shop[0]->deSerialize();

	shop[1]->setName(name2);
	shop[1]->setAdress(adress2);
	shop[1]->setYear(year2);
	shop[1]->setNumber(number2);
	shop[1]->setTotalProfit(totalProfit2);

	shop[2]->setName(name3);
	shop[2]->setAdress(adress3);
	shop[2]->setYear(year3);
	shop[2]->setNumber(number3);
	shop[2]->setTotalProfit(totalProfit3);

	int* sale1 = new int[90];
	int* sale2 = new int[90];
	int* sale3 = new int[90];

	srand(time(0));
	for (int i = 0; i < 90; i++)
	{
		sale1[i] = rand() % 1000;
		(*shop[0]) += sale1[i];
		sale2[i] = rand() % 1000;
		(*shop[1]) += sale2[i];
		sale3[i] = rand() % 1000;
		(*shop[2]) += sale3[i];
	}
	//sort(*shop[0], *shop[1], *shop[2]);
	shop[0]->payTax();
	shop[1]->payTax();
	shop[2]->payTax();
	shop[0]->serialize();
	system("pause");
}

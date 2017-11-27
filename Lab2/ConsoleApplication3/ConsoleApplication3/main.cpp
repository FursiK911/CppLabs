#include <iostream>
#include <iomanip>
#include "Shop.h"
using namespace std;
void sort(Shop& x, Shop& y, Shop& z)
{
	Shop arr[3];			//Создаем и заполняем временный массив
	arr[0].setName(x.getName());
	arr[0].setAdress(x.getAdress());
	arr[0].setYear(x.getYear());
	arr[0].setNumber(x.getNumber());
	arr[0].setTotalProfit(x.getTotalProfit());

	arr[1].setName(y.getName());
	arr[1].setAdress(y.getAdress());
	arr[1].setYear(y.getYear());
	arr[1].setNumber(y.getNumber());
	arr[1].setTotalProfit(y.getTotalProfit());

	arr[2].setName(z.getName());
	arr[2].setAdress(z.getAdress());
	arr[2].setYear(z.getYear());
	arr[2].setNumber(z.getNumber());
	arr[2].setTotalProfit(z.getTotalProfit());

	int i;
	cout << "1.Сортировка по убыванию общей прибыли\n2.Сортировка по убыванию среднего прироста прибыли" << endl;
	cin >> i;
	switch (i)
	{
	case 1:
		for (int i = 0; i < 2; i++) //Сортируем...
			for (int j = 2; j > i; j--)
				if (arr[j - 1].getTotalProfit() < arr[j].getTotalProfit())
				{
					int tmp = arr[j - 1].getTotalProfit();
					arr[j - 1].setTotalProfit(arr[j].getTotalProfit());
					arr[j].setTotalProfit(tmp);
				}
		//Выводим полученные результаты
		cout << setw(23) << arr[0].getName() << setw(23) << arr[1].getName() << setw(23) << arr[2].getName() << endl; 
		cout << setw(23) << arr[0].getAdress() << setw(23) << arr[1].getAdress() << setw(23) << arr[2].getAdress() << endl;
		cout << setw(23) << arr[0].getYear(1) << setw(23) << arr[1].getYear(1) << setw(23) << arr[2].getYear(1) << endl;
		cout << setw(23) << arr[0].getNumber() << setw(23) << arr[1].getNumber() << setw(23) << arr[2].getNumber() << endl;
		cout << setw(23) << arr[0].getTotalProfit() << setw(23) << arr[1].getTotalProfit() << setw(23) << arr[2].getTotalProfit() << endl;
		cout << endl;
		break;
	case 2:
		for (int i = 0; i < 2; i++) //Сортируем...
			for (int j = 2; j > i; j--)
				if ((arr[j - 1].getTotalProfit()/90) < (arr[j].getTotalProfit()/90))
				{
					int tmp = arr[j - 1].getTotalProfit();
					arr[j - 1].setTotalProfit(arr[j].getTotalProfit());
					arr[j].setTotalProfit(tmp);
				}
		//Выводим полученные результаты
		cout << setw(23) << arr[0].getName() << setw(23) << arr[1].getName() << setw(23) << arr[2].getName() << endl;
		cout << setw(23) << arr[0].getAdress() << setw(23) << arr[1].getAdress() << setw(23) << arr[2].getAdress() << endl;
		cout << setw(23) << arr[0].getYear(1) << setw(23) << arr[1].getYear(1) << setw(23) << arr[2].getYear(1) << endl;
		cout << setw(23) << arr[0].getNumber() << setw(23) << arr[1].getNumber() << setw(23) << arr[2].getNumber() << endl;
		cout << setw(23) << arr[0].getTotalProfit() << setw(23) << arr[1].getTotalProfit() << setw(23) << arr[2].getTotalProfit() << endl;
		cout << endl;
		break;
	default:
		break;
	}
}
void main()
{
	setlocale(LC_ALL, "Russian");

	string name1 = "Fusion";
	string adress1 = "Университетская_улица,46,Донецк";
	tm year1;
	year1.tm_year = 1998;
	int number1 = 1;
	int totalProfit1 = 0;

	string name2 = "Buta";
	string adress2 = "улица_Щорса,32,Донецк";
	tm year2;
	year2.tm_year = 1999;
	int number2 = 2;
	int totalProfit2 = 0;

	string name3 = "Fumari";
	string adress3 = "улица_Артёма,84,Донецк";
	tm year3;
	year3.tm_year = 2000;
	int number3 = 3;
	int totalProfit3 = 0;

	Shop* fusion = new Shop();
	Shop* buta = new Shop();
	Shop fumari(name3, adress3, year3, number3, totalProfit3);

	fusion->setName(name1);
	fusion->setAdress(adress1);
	fusion->setYear(year1);
	fusion->setNumber(number1);
	fusion->setTotalProfit(totalProfit1);

	fusion->deSerialize();

	buta->setName(name2);
	buta->setAdress(adress2);
	buta->setYear(year2);
	buta->setNumber(number2);
	buta->setTotalProfit(totalProfit2);

	int* saleFusion = new int[90];
	int* saleButa = new int[90];
	int* saleFumari = new int[90];

	srand(time(0));
	for (int i = 0; i < 90; i++)
	{
		saleFusion[i] = rand() % 1000;
		(*fusion) += saleFusion[i];
		saleButa[i] = rand() % 1000;
		(*buta) += saleButa[i];
		saleFumari[i] = rand() % 1000;
		fumari += saleFumari[i];
	}
	cout << fusion->getTotalProfit() << endl;
	sort(*fusion, *buta, fumari);
	fusion->serialize();
	delete fusion;
	delete buta;
	system("pause");
}

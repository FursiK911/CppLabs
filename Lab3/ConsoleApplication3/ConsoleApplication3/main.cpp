#include <iostream>
#include <iomanip>
#include "Shop.h"
#include "Boutique.h"
#include "Direction.h"
#include "Market.h"
#include "Pharmacy.h"
#include "ITaxPayment.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");

	string name1 = "АйБолит";
	string adress1 = "Университетская_улица,46,Донецк";
	tm year1;
	year1.tm_year = 1998;
	int number1 = 1;
	int totalProfit1 = 0;
	int clientDiscount1 = 8;
	tm work1;
	string type1 = "Круглосуточно";

	string name2 = "Болотный доктор";
	string adress2 = "улица_Щорса,32,Донецк";
	tm year2;
	year2.tm_year = 1999;
	int number2 = 2;
	int totalProfit2 = 0;
	int clientDiscount2 = 12;
	tm word2;
	string type2 = "Не круглосуточно";

	string name3 = "Сто рентген";
	string adress3 = "улица_Артёма,84,Донецк";
	tm year3;
	year3.tm_year = 2000;
	int number3 = 3;
	int totalProfit3 = 0;
	int clientDiscount3 = 3;
	tm word3;
	string type3 = "Круглосуточно";

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
	shop[0]->payTax();
	shop[1]->payTax();
	shop[2]->payTax();
	Boutique* b[1] = dynamic_cast<Boutique*>(shop[0]);
	Market m;
	m.calculateDirection(shop, 2);
	//shop[0]->serialize();
	delete sale1;
	delete sale2;
	delete sale3;
	system("pause");
}

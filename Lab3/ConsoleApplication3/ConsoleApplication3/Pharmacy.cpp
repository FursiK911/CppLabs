#include "Pharmacy.h"



Pharmacy::Pharmacy()
{
	percent = 1;
}

Pharmacy::~Pharmacy()
{
}

void Pharmacy::payTax()
{
	tax = (getTotalProfit() * percent) / 100;
	std::cout << "Налог составляет : " << tax << endl;
	setTotalProfit(getTotalProfit() - tax);
}

int Pharmacy::getTax()
{
	return tax;
}

void Pharmacy::setPercent(int p)
{
	percent = p;
}

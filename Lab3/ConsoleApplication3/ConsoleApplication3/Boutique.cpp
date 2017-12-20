#include "Boutique.h"



Boutique::Boutique()
{
	percent = 2;
}


Boutique::~Boutique()
{
}

void Boutique::payTax()
{
	tax = (getTotalProfit() * percent) / 100;
	std::cout << "Налог составляет : " << tax << endl;
	setTotalProfit(getTotalProfit() - tax);
}

int Boutique::getTax()
{
	return tax;
}

void Boutique::setPercent(int p)
{
	percent = p;
}

char * Boutique::getDirection()
{
	return direction;
}

void Boutique::setDirection(char * dir)
{
	direction = dir;
}

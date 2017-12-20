#pragma once
#include <iostream>
#include "Shop.h"
#include "ITaxPayment.h"
class Boutique :
	public Shop, public ITaxPayment
{
private:
	int tax;
	int percent;
	char* direction;
public:
	Boutique();
	~Boutique();
	void payTax();
	int getTax();
	void setPercent(int p);
	char* getDirection();
	void setDirection(char* dir);
};


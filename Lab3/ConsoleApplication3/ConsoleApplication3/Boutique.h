#pragma once
#include <iostream>
#include "Shop.h"
#include "ITaxPayment.h"
#include "Direction.h"
class Boutique :
	public Shop, public ITaxPayment, public Direction
{
private:
	int tax;
	int percent;
public:
	Boutique();
	~Boutique();
	void payTax();
	int getTax();
	void setPercent(int p);
};


#pragma once
#include <iostream>
#include "Shop.h"
#include "ITaxPayment.h"
class Pharmacy :
	public Shop, public ITaxPayment
{
private:
	int tax;
	int percent;
public:
	Pharmacy();
	~Pharmacy();
	void payTax();
	int getTax();
	void setPercent(int p);
};


#pragma once
#include "Shop.h"
#include "Boutique.h"
class Market :
{
private:
	int countClothing;
	int countFood;
	int countShoes;
	double percentClothing;
	double percentFood;
	double percentShoes;
public:
	Market();
	~Market();
	void calculateDirection(Boutique* boutique, int lenght);
};


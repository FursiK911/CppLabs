#include "Market.h"



Market::Market()
{
}


Market::~Market()
{
}

void Market::calculateDirection(Boutique* boutique, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		if (boutique[i].getDirection() == "Clothing")
			countClothing++;
		if (boutique[i].getDirection() == "Food")
			countFood++;
		if (boutique[i].getDirection() == "Shoes")
			countShoes++;
	}
	percentClothing = (lenght / 100) * countClothing;
	percentFood = (lenght / 100) * countFood;
	percentShoes = (lenght / 100) * countShoes;
	cout << percentClothing << endl;
	cout << percentFood << endl;
	cout << percentShoes << endl;
}

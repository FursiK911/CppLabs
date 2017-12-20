#pragma once

#include "Hand.h"
#include "Deck.h"

class Gambler
{
private:
	const int maxcounthands = 10;
    int counthands = 0;
	int money;

	Hand* hands;

	
public:
	Hand* getHand();
	int getmoney();
	int getmaxcounthands();
	int getcounthands();
	void setcounthands(int counthands);
	void setmoney(int money);
	
	void split();

	void clear();
	void takeCards(Deck* deck);


	Gambler(int money);
	~Gambler();
};


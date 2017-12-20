#pragma once

#include "Hand.h"

class Dealer
{
	Hand* hand;
public:
	Hand* getHand();

	Dealer();
	~Dealer();
};


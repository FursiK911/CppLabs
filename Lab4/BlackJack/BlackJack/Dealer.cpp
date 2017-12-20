#include "Dealer.h"



Dealer::Dealer()
{
	hand = new Hand();
}


Dealer::~Dealer()
{
}

Hand* Dealer::getHand()
{
	return hand;
}
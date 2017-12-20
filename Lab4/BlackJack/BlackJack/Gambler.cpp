#include "Gambler.h"
#include "Deck.h"

Gambler::Gambler(int money) : money(money)
{
	hands = new Hand[maxcounthands];
}

Gambler::~Gambler()
{ 
	delete hands;
}

int Gambler::getmoney()
{
	return money;
}

int Gambler::getmaxcounthands()
{
	return maxcounthands;
}

int Gambler::getcounthands()
{
	return counthands;
}

void Gambler::setmoney(int money)
{
	this->money = money;
}

void Gambler::setcounthands(int counthands)
{
	this->counthands = counthands;
}

void Gambler::clear()
{
	for (int i = counthands; i >= 0; --i)
	{
		hands[i].clear();
	}

	setcounthands(0);
}

void Gambler::takeCards(Deck* deck)
{
	for (int i = 0; i <= counthands; i++)
	{
		hands[i].takeCard(deck);
	}
}

Hand* Gambler::getHand()
{
	return hands;
}

void Gambler::split()
{
	int tmp_counthands = getcounthands();
	for (int cHand = 0; cHand <= tmp_counthands; cHand++)
	{
		if (hands[cHand].isSplit())
		{
			counthands++;
			int mid = hands[cHand].getcountcards() % 2 == 0 ? hands[cHand].getcountcards() / 2 : hands[cHand].getcountcards() / 2 + 1;

			for (int i = mid; i < hands[cHand].getcountcards(); i++)
			{
				std::swap
				(
					hands[cHand].getCards()[i],
					hands[counthands].getCards()[hands[counthands].getcountcards()]
				);
				hands[cHand].setcountcards(hands[cHand].getcountcards() - 1);
				hands[counthands].setcountcards(hands[counthands].getcountcards() + 1);
			}
		}
	}
}
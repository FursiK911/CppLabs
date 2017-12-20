#pragma once

#include "Card.h"
#include "Deck.h"

class Hand
{
private:
	Card* cards;
	int cardscount = 0;

	const int maxcardscount = 11;

	int random();
	int checkValueAce(int value, int countAce);
	
public:
	Card* getCards();
	int getmaxcardscount();
	int getcountcards();
	
	void setcountcards(int cardscount);
	int calculateValue();
	void clear();
	void takeCard(Deck* deck);

	bool isSplit();

	bool checkBJ(int value);
	bool checkGBJ(int value);

	bool checkThreeSeven(int value);

	Hand();
	virtual ~Hand();
};


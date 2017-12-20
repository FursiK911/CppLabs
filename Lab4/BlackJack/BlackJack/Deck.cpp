#include "Deck.h"
#include "Enum.h"
#include "Card.h"

#include <random>
#include <ctime>
#include <iostream>

Deck::Deck()
{

}

int Deck::getCountCards()
{
	return countCards;
}

int Deck::getNumberCard()
{
	return numbercard;
}

Card Deck::takeCard()
{
	numbercard++;
	return cards[numbercard];
}

void Deck::createDeck()
{
	int start = (countCards == 52) ? 2 : 6;
	int markCard = 0;
	for (int csuit = 0; csuit < countSuit; csuit++)
	{
		for (int cname = start; cname < countCards / countSuit + start; cname++)
		{
				cards[markCard].setName((NameCard)cname);
				cards[markCard++].setSuit((Suit)csuit);
		}
	}
}

void Deck::shuffleDeck()
{
	//srand(time(0));
	for (int i = 1; i < countCards; i++)
	{
		std::swap(cards[i], cards[(rand() % i)]);
	}
}

void Deck::initDeck(TypeDeck type)
{
	if (type == TypeDeck::Cut)
		countCards = 36;
	if (type == TypeDeck::Full)
		countCards = 52;
	cards = new Card[countCards];
	createDeck();
	shuffleDeck();
	shuffleDeck();
}

Deck::~Deck()
{
	delete[] cards;
}
#pragma once

#include "Gambler.h"
#include "Dealer.h"
#include "Deck.h"
#include "Card.h"

class Game
{
	int cash; 
	bool doubleNow = false;
	int countdecks;
	Deck* decks;

	Dealer* dealer;
	Gambler* gambler;


public:
	Game(Dealer* dealer, Gambler* gambler);
	~Game();

	int getChoice();

	void setDecks(Deck* decks, int count);
	void takeCardsDealer();
	void takeCardsGambler();
	void calculateScore();
	void printStatusDeck();
	void printCardsDealer(bool variant);
	void printCardsGambler();
	void printMenu();	
	void dropCards();
	bool init();
	bool checkPerebor();
	bool isSplit();
	bool isDouble();
	bool replicateChoice(int choice);

};


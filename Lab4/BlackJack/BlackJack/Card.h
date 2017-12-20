#pragma once

#include "Enum.h"

#include <iostream>

class Card
{
protected:
	Suit suit;
	NameCard name;
public:
	Suit getSuit() const;
	NameCard getName() const;
	void setName(NameCard innerSuit);
	void setSuit(Suit innerSuit);

	friend std::ostream& operator<< (std::ostream& o ,const Card& card );

	Card();
	Card(Suit suit, NameCard name);
	virtual ~Card();
};


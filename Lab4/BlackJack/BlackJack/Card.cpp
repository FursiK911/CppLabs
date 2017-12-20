#include "Card.h"


Card::Card() 
{
	suit = Suit::None;
	name = NameCard::None;
}
Card::Card(Suit suit, NameCard name) : suit(suit), name(name) { }
Card::~Card() { }

Suit Card::getSuit() const
{
	return suit;
}

void Card::setSuit(Suit innerSuit)
{
	suit = innerSuit;
}

NameCard Card::getName() const
{
	return name;
}

void Card::setName(NameCard innername)
{
	name = innername;
}

std::ostream& operator<<(std::ostream& o,const Card& card)
{
	int dname = (int)card.getName();
	char suit = (char)((int)(card.getSuit()) + 3);
	switch (dname)
	{
	case 11:
		o << 'Â' << suit << " ";
		break;
	case 12:
		o << 'Ä' << suit << " ";
		break;
	case 13:
		o << 'Ê' << suit << " ";
		break;
	case 14:
		o << 'À' << suit << " ";
		break;
	default:
		o << dname << suit << " ";
		break;
	}
	return o;
}
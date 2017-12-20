
#include <iostream>

#include "Game.h"
#include "Gambler.h"
#include "Dealer.h"


Game::Game(Dealer* dealer, Gambler* gambler) : dealer(dealer), gambler(gambler) { }
Game::~Game() { }

void Game::setDecks(Deck* decks, int count)
{
	this->decks = decks;
	countdecks = count;
}

bool Game::init()
{
	if (0 >= gambler->getmoney())
	{
		std::cout << "\n��� ������ ����, ��������� ������� ���� ���������� �� ������ :)";
		std::cout << "\n�����\n";
	
	}

	int tmp_money;
	std::cout << "\n��� ����: " << gambler->getmoney();
	std::cout << "\n���� ������: ";
	std::cin >> tmp_money;

	if (tmp_money <= 0)
	{
		std::cout << "\n���� ������ �� ����� ���� ������ ��� ����� 0";
		return false;
	}

	if (tmp_money <= gambler->getmoney())
	{
		gambler->setmoney(gambler->getmoney() - tmp_money);
		cash = tmp_money;
		return true;
	}
	else
	{
		std::cout << "\n��������� ����� ��� ������";
		return false;
	}	
}

void Game::printStatusDeck()
{
	std::cout << "\n������: "; 
	for (int i = 0; i < countdecks; i++)
	{	
		std::cout << "[" << decks[i].getCountCards() - decks[i].getNumberCard() << "] ";
	}
}

void Game::printCardsDealer(bool isVisible)
{
	if (isVisible == 0)
	{
		std::cout << "\n�����: ";

		for (int i = 0; i < dealer->getHand()->getcountcards(); i++)
		{
			if (i == 0)
				std::cout << dealer->getHand()->getCards()[i];
			else
				std::cout << "??";
		}
	}
	else
	{
		std::cout << "\n�����: ";

		for (int i = 0; i < dealer->getHand()->getcountcards(); i++)
		{
			std::cout << dealer->getHand()->getCards()[i];
		}
	}


}

void Game::printCardsGambler()
{
	for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
	{
		std::cout << "\n���� " << cHand + 1  <<  " ���� : ";
		for (int i = 0; i < gambler->getHand()[cHand].getcountcards(); i++)
		{
			std::cout << gambler->getHand()[cHand].getCards()[i];
		}
		std::cout << std::endl;
	}
}

void Game::takeCardsDealer()
{
	dealer->getHand()->takeCard(decks);
	dealer->getHand()->takeCard(decks);
}

void Game::takeCardsGambler()
{
	gambler->takeCards(decks);
	gambler->takeCards(decks);
}

void Game::printMenu()
{
	if (isSplit())
		std::cout << "\n1.������" << std::endl << "2.���" << std::endl << "3.�����\n" << std::endl;
	else if (isDouble() && doubleNow == false)
	{
		std::cout << "\n1.������" << std::endl << "2.���" << std::endl << "3.�������\n" << std::endl;
	}
	else
		std::cout << "\n1.������" << std::endl << "2.���\n";
}

int Game::getChoice()
{
	int tmp;
	std::cin >> tmp;
	return tmp;
}

bool Game::replicateChoice(int choice)
{

	switch (choice)
	{
	case 1:
		//dealer->getHand();
		calculateScore();
		return false;
	case 2:
		gambler->takeCards(decks);
		return checkPerebor();
	case 3:
		if (isSplit())
		{
			gambler->split();

			for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
			{
				if (gambler->getHand()[cHand].getcountcards() != 2)
				{
					gambler->getHand()[cHand].takeCard(decks);
				}
			}
			return true;
		}
		if (isDouble() && doubleNow == false)
		{
			cash *= 2;
			doubleNow = true;
		}
		break;
	default:
		break;
	}
	printMenu();
	replicateChoice(getChoice());
}

void Game::calculateScore()
{
	printCardsDealer(true);
	printCardsGambler();
	std::cout << std::endl;

	int countWins(0);
	int wins = 0;

	int dealer_value = dealer->getHand()->calculateValue();

	for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
	{
		int gambler_value = gambler->getHand()[cHand].calculateValue();

		if (dealer_value <= 21 && gambler_value <= 21)
		{
			if (dealer_value == gambler_value)
			{
				gambler->setmoney(gambler->getmoney() + cash);
			}
			if (dealer_value < gambler_value)
			{
				countWins++;
				wins++;
			}

			if (dealer_value > gambler_value)
			{
				countWins--;

			}
		}
		else
		{
			// 100 - blackjack 
			// 101 - goldenblackjack
			if (gambler_value < 99)
				countWins--;
			else if (dealer_value > gambler_value)
				countWins--;
			else if (gambler_value == 102)
				cash *= 1.5;
			else
			{
				countWins++;
				wins++;
			}
		}
	}
		std::cout << "���������� �����: " << wins << std::endl << "���������� ���: " << gambler->getcounthands() + 1 << std::endl;
		
		if(countWins == 0)
			std::cout << "�����. " << std::endl << "�� �������� ��� ����� �����.";
		
		if (countWins > 0)
		{
			std::cout << "�����������! �� ��������! ��� �������: " << cash * countWins << ".";
			gambler->setmoney(gambler->getmoney() + (cash * 2));
		}

		if (countWins < 0)
			std::cout << "���! �� ���������!";
	
	std::cout << "�����: " << gambler->getmoney();
}

void Game::dropCards()
{
	dealer->getHand()->clear();
	gambler->clear();
	doubleNow = false;
}

bool Game::checkPerebor()
{
	try
	{
		for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
		{
			int gambler_value = gambler->getHand()[cHand].calculateValue();

			if (gambler->getHand()[cHand].calculateValue() > 21)
			{
				throw cHand;
			}
		}
		return true;
	}
	catch(int numberHand)
	{
		std::cout << "�������! �� " << numberHand + 1 << " ����.";
		return false; 
	}
}

bool Game::isSplit()
{
	for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
	{
		if(gambler->getHand()[cHand].isSplit())
			return true;
	}
	return false;
}

bool Game::isDouble()
{
	int tmp_value;
	for (int cHand = 0; cHand <= gambler->getcounthands(); cHand++)
	{
		tmp_value = gambler->getHand()[cHand].calculateValue();
		if (tmp_value >= 9 && tmp_value <= 11)
		{
			if (cash * 2 <= gambler->getmoney())
				return true;
			else
			{
				std::cout << "����� ������ ������" << std::endl;
				return false;
			}
		}
	}
	return false;
}
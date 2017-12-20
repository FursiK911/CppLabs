
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
		std::cout << "\nВаш баланс пуст, совершите депозит либо устройтесь на работу :)";
		std::cout << "\nУдачи\n";
	
	}

	int tmp_money;
	std::cout << "\nВаш счет: " << gambler->getmoney();
	std::cout << "\nВаша ставка: ";
	std::cin >> tmp_money;

	if (tmp_money <= 0)
	{
		std::cout << "\nВаша ставка не может быть меньше или равна 0";
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
		std::cout << "\nНехватает денег для ставки";
		return false;
	}	
}

void Game::printStatusDeck()
{
	std::cout << "\nКолоды: "; 
	for (int i = 0; i < countdecks; i++)
	{	
		std::cout << "[" << decks[i].getCountCards() - decks[i].getNumberCard() << "] ";
	}
}

void Game::printCardsDealer(bool isVisible)
{
	if (isVisible == 0)
	{
		std::cout << "\nДилер: ";

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
		std::cout << "\nДилер: ";

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
		std::cout << "\nВаша " << cHand + 1  <<  " рука : ";
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
		std::cout << "\n1.Хватит" << std::endl << "2.Еще" << std::endl << "3.Сплит\n" << std::endl;
	else if (isDouble() && doubleNow == false)
	{
		std::cout << "\n1.Хватит" << std::endl << "2.Еще" << std::endl << "3.Удвоить\n" << std::endl;
	}
	else
		std::cout << "\n1.Хватит" << std::endl << "2.Еще\n";
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
		std::cout << "Количество побед: " << wins << std::endl << "Количество рук: " << gambler->getcounthands() + 1 << std::endl;
		
		if(countWins == 0)
			std::cout << "Ровно. " << std::endl << "Вы остались при своих очках.";
		
		if (countWins > 0)
		{
			std::cout << "Поздравляем! Вы выиграли! Ваш выигрыш: " << cash * countWins << ".";
			gambler->setmoney(gambler->getmoney() + (cash * 2));
		}

		if (countWins < 0)
			std::cout << "Увы! Вы проиграли!";
	
	std::cout << "Всего: " << gambler->getmoney();
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
		std::cout << "Перебор! На " << numberHand + 1 << " руке.";
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
				std::cout << "Нужно больше золота" << std::endl;
				return false;
			}
		}
	}
	return false;
}
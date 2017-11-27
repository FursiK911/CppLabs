#include <iostream>
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Summator.h"
#include "Divisor.h"
#include "ILoggable.h"
#include "IShuffle.h"

using namespace std;

void main()
{
	ExpressionEvaluator* evaluators[3];

	evaluators[0] = new CustomExpressionEvaluator();
	double custom_operands[] = { 5, 16, -3, 10, 12, 2, 12, 15, 23, -18 , 17, 22, -30};
	evaluators[0]->setOperands(custom_operands, 13);

	evaluators[1] = new Summator();
	double summator_operands[] = { 5.6, -2.1, 3.2, 1.5, 3.8, 12.0};
	evaluators[1]->setOperands(summator_operands, 6);

	evaluators[2] = new Divisor();
	evaluators[2]->setOperand(0, 10);
	evaluators[2]->setOperand(1, -2);
	evaluators[2]->setOperand(2, 2.5);
	evaluators[2]->setOperand(3, 15);
	evaluators[2]->setOperand(4, -4);

	for (int i = 0; i < 3; i++)
	{
		double res = evaluators[i]->calculate();
		evaluators[i]->logToFile("lab3.log");
		evaluators[i]->logToScreen();
		std::cout << "\nResult: " << res << std::endl << std::endl;
	}

	for (int i = 0; i < 3; i++)
	{
		IShuffle* loga = dynamic_cast<IShuffle*>(evaluators[i]);

		if (loga)
		{
			loga->shuffle();
			double res = evaluators[i]->calculate();
			evaluators[i]->logToScreen();
			std::cout << "\nResult: " << res << std::endl << std::endl;
		}
	}


	system("pause");

	delete evaluators[0];
	delete evaluators[1];
	delete evaluators[2];
}
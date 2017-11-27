#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator : public ExpressionEvaluator
{
private:
	double result;
public:
	CustomExpressionEvaluator();
	~CustomExpressionEvaluator();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(int i, int j);
};


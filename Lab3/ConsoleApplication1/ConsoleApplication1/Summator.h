#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Summator : public ExpressionEvaluator, public IShuffle
{
private:
	double sum;
public:
	Summator();
	~Summator();

	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(int i, int j);
};


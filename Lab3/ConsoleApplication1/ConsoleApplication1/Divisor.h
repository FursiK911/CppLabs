#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Divisor :
	public ExpressionEvaluator, public IShuffle
{
private:
	double div;
public:
	Divisor();
	~Divisor();
	double calculate();
	void logToScreen();
	void logToFile(const std::string& filename);

	void shuffle();
	void shuffle(int i, int j);
};


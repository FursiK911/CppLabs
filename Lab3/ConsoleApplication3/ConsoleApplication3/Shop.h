#pragma once
#include <string>
#include <ctime>
using namespace std;

class Shop
{
private:
	string name;
	string adress;
	tm year;
	unsigned short int number;
	int totalProfit;
	int income;
	tm workingTime;
	int numberClientDiscount;
	string type;
public:
	Shop();
	Shop(string n, string a, tm y, int numb, int t);
	~Shop();
	string getName();
	string getAdress();
	tm getYear();
	int getYear(int);
	int getNumber();
	int getTotalProfit();
	int getIncome();
	tm getWorkingTime();
	int getNumberClientDiscount();
	string getType();
	void setName(string n);
	void setAdress(string a);
	void setYear(tm);
	void setNumber(int n);
	void setTotalProfit(int t);
	void setIncome(int i);
	void setWorkingTime(tm workT);
	void setNumberClientDiscount(int number);
	void setType(string t);
	void operator+=(int x);
	void serialize();
	void deSerialize();
	void serialize(string filename);
	void deSerialize(std::string filename);
	virtual void payTax()=0;
	virtual int getTax()=0;
	virtual void setPercent(int p)=0;
	virtual void setDirection(char* dir) = 0;
	virtual char* getDirection() = 0;
};
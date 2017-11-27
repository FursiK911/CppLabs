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
	void setName(string n);
	void setAdress(string a);
	void setYear(tm);
	void setNumber(int n);
	void setTotalProfit(int t);
	void operator+=(int x);
	void serialize();
	void deSerialize();
	void serialize(string filename);
	void deSerialize(std::string filename);
};
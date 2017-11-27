#include "Shop.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>


Shop::Shop()
{
}

Shop::Shop(string n, string a, tm y, int numb, int t)
{
	name = n;
	adress = a;
	year = y;
	number = numb;
	totalProfit = t;
}

Shop::~Shop()
{
}

string Shop::getName()
{
	return name;
}

string Shop::getAdress()
{
	return adress;
}

tm Shop::getYear()
{
	return year;
}

int Shop::getYear(int)
{
	return year.tm_year;
}

int Shop::getNumber()
{
	return number;
}

int Shop::getTotalProfit()
{
	return totalProfit;
}

void Shop::setName(string n)
{
	name = n;
}

void Shop::setAdress(string a)
{
	adress = a;
}

void Shop::setYear(tm y)
{
	year.tm_year = y.tm_year;
}

void Shop::setNumber(int n)
{
	number = n;
}

void Shop::setTotalProfit(int t)
{
	totalProfit = t;
}

void Shop::operator+=(int x)
{
	totalProfit += x;
}

void Shop::serialize()
{
	string path = "data.txt";
	ofstream fout(path, ios_base::trunc);
	fout << name << " " << adress << " " << year.tm_year << " " << number << " " << totalProfit << " " << endl;
	fout.close();
}

void Shop::deSerialize()
{
	string path = "data.txt";
	ifstream fin(path, ios_base::in);
	fin >> name >> adress >> year.tm_year >> number >> totalProfit;
	fin.close();
}

void Shop::serialize(string filename)
{
	ofstream fout(filename, ios_base::trunc);
	fout << name << ";" << adress << ";" << year.tm_year << ";" << number << ";" << totalProfit << ";" << endl;
	fout.close();
}

void Shop::deSerialize(std::string filename)
{
	ifstream fin(filename, ios_base::in);
}
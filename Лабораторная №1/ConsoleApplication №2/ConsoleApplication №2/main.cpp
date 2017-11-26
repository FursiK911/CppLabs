#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void processArray(double *mas1d,int n)
{
	cout<<"\n";
	double** mas2d = new double*[5];

	for(int i=0;i<5;i++)
	{
		*(mas2d+i) = new double [5];
	}

	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			*(*(mas2d + i) + j) = *(mas1d+i*5+j);
			cout.width(10);
			cout<<*(*(mas2d + i) + j);
		}
		cout<<"\n";
	}

	cout<<"\n";

	for(int i=0;i<5;++i)
	{
		for(int j=0;j<5;++j)
		{
			if(j==0)
			{
				*(*(mas2d + i) + j) = *(*(mas2d + i) + j+1) + *(*(mas2d + i) + j+2) + *(*(mas2d + i) + j+3) + *(*(mas2d + i) + j+4);
			}
			cout.width(10);
			cout<<*(*(mas2d + i) + j);
		}
		cout<<"\n";
	}
}

void viewArray(double *mas1d,int n)
{
	//cout<<"\n";
	for(int i = 0; i<n;i++)
	{
		cout.width(10);
		cout<<*(mas1d+i);
	}
	cout<<"\n";
	processArray(mas1d,n);
}

void createArray()
{
	const unsigned int lenght = 25;
	const double Pi = 3.14;
	double *mas1d = new double[lenght];
	for(int i = 0; i<lenght;i++)
	{
		*(mas1d+i) = i*sin(Pi*i/25);
	}
	viewArray(mas1d,lenght);
}

void main()
{
	setlocale(LC_ALL,"Russian");

	createArray();
	system("pause");
}
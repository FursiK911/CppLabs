#include <iomanip>
#include <iostream>
#include <cstring>
#include <cctype>
#include <string.h>
using namespace std;

void main()
{
	char str[]="Hello world!",vowels[]="AaEeIiOoUuYy";
	int k = 0;
	int i = 0;	
	while(k!=strlen(str))
	{
		if (i != strlen(vowels))
		{
			if (str[k] == vowels[i])
			{
				str[k] = (char)toupper(str[k]);
				k++;
				i = 0;
			}
			else
			{
				i++;
			}
		}
		else
		{
			k++;
			i = 0;
		}
	}
	cout << str;
	system("pause");
}
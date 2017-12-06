#include <cstring>
#include <cstdio>
#include <iostream>

const char* reverseChar(const char* s, int c)
{
	int len = 0; // стартовый индекс
	// указатель на оставшуюся часть строки (его нужно вернуть)
	const char* rest_of_string = NULL;
	// проходим до конца строки (пока не встретим символ '\0')
	while (s[len] != '\0')
	{
		// если очередной символ оказался равен искомому с,
		if (s[len] == c)
		{
			// то запоминаем указатель на него
			rest_of_string = s + len;
			break;
		}
		len++;
	}
	// возвращаем последний присвоенный указатель
	return rest_of_string;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	// тестовая строка
	char s[] = "www.some_caddress.and_something_else.com";
	// проверяем стандартную функцию
	// (ищем последнее вхождение символа "c")
	const char* standard_result = strrchr(s, 'с');
	// проверяем свою версию стандартной функции
	const char* my_result = reverseChar(s, 'с');
	// выводим на экран строку,
	// затем результат стандартной функции
	// и затем результат своей версии
	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",
	s, standard_result, my_result);
	for(int i = 0;;i++)
		break;
	system("pause");
	return 0;
}

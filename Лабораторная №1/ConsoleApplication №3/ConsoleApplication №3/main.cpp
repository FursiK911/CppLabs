#include <cstring>
#include <cstdio>
#include <iostream>

const char* reverseChar(const char* s, int c)
{
	int len = 0; // ��������� ������
	// ��������� �� ���������� ����� ������ (��� ����� �������)
	const char* rest_of_string = NULL;
	// �������� �� ����� ������ (���� �� �������� ������ '\0')
	while (s[len] != '\0')
	{
		// ���� ��������� ������ �������� ����� �������� �,
		if (s[len] == c)
		{
			// �� ���������� ��������� �� ����
			rest_of_string = s + len;
			break;
		}
		len++;
	}
	// ���������� ��������� ����������� ���������
	return rest_of_string;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	// �������� ������
	char s[] = "www.some_caddress.and_something_else.com";
	// ��������� ����������� �������
	// (���� ��������� ��������� ������� "c")
	const char* standard_result = strrchr(s, '�');
	// ��������� ���� ������ ����������� �������
	const char* my_result = reverseChar(s, '�');
	// ������� �� ����� ������,
	// ����� ��������� ����������� �������
	// � ����� ��������� ����� ������
	printf("Initial string: %s\nStandard: %s\nMy version: %s\n",
	s, standard_result, my_result);
	for(int i = 0;;i++)
		break;
	system("pause");
	return 0;
}

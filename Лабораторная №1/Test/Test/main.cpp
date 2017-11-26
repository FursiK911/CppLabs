#include <cstdio>
#include <cstdlib>
#include <ctime>

double processArray(double arr[], unsigned int N, bool outs[])
{
// ���������� ������� ���������� ������� [-15.0..15.0]
for (unsigned int i = 0; i < N; ++i)
{
arr[i] = (double)(rand() % 30) - 15.0;
}
double average = 0.0;
// ������� �������� �������� ���������
for (unsigned int i = 0; i < N; ++i)
{
average += arr[i];
}
average /= N;
// ������������ �������� ������� (�� �������)
for (unsigned int i = 0; i < N; ++i)
{
outs[i] = arr[i] > average;
}
return average; // ���������� �������
}

void printArrayBool(bool* arr, unsigned int N)
{
for (unsigned int i = 0; i < N; ++i)
{
arr[i] ? printf("T ") : printf("F ");
}
printf("\n");
}

	void printArray(double* arr, unsigned int N)
	{
		for(int i = 0; i<N;i++)
			printf("arr[i]");
	}
int main()
{
const unsigned int LEN = 20;
// ������� ������ � �������������� ��� ������
double a[LEN] = { 0.0 };
// ����� ������ � ���������� false
bool b[LEN] = { false };
// ������������� ���������� ��������� �����
srand(0);
// ������� �������� �������� � ������� �;
// ��������� ������� b
double result = processArray(a, LEN, b);
// ����� �������� �� �����
printArray(a, LEN);
printArrayBool(b, LEN);
// ...� �������� �������� ��������� ������� �
printf("Average: %g\n\n", result);
system("pause");
return 0;
}

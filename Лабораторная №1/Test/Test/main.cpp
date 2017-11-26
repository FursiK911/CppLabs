#include <cstdio>
#include <cstdlib>
#include <ctime>

double processArray(double arr[], unsigned int N, bool outs[])
{
// заполнение массива случайными числами [-15.0..15.0]
for (unsigned int i = 0; i < N; ++i)
{
arr[i] = (double)(rand() % 30) - 15.0;
}
double average = 0.0;
// подсчет среднего значения элементов
for (unsigned int i = 0; i < N; ++i)
{
average += arr[i];
}
average /= N;
// формирование булевого массива (по заданию)
for (unsigned int i = 0; i < N; ++i)
{
outs[i] = arr[i] > average;
}
return average; // возвращаем среднее
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
// создаем массив и инициализируем его нулями
double a[LEN] = { 0.0 };
// булев массив – значениями false
bool b[LEN] = { false };
// инициализация генератора случайных чисел
srand(0);
// подсчет среднего значения в массиве а;
// изменение массива b
double result = processArray(a, LEN, b);
// вывод массивов на экран
printArray(a, LEN);
printArrayBool(b, LEN);
// ...и среднего значения элементов массива а
printf("Average: %g\n\n", result);
system("pause");
return 0;
}

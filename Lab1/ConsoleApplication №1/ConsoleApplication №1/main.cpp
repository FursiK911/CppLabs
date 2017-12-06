#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <clocale>
	
	int* processArray(int* arr,int* negativeArray, unsigned int N,int* pindex)
	{
		srand(time(0));
		int a,b;
		//int negativeNumber(0);
		do
		{
			printf("\n¬ведите начальный интервал ( a<0 ):");
			scanf("%d", &a);
		}
		while(a>=0);
		printf("¬ведите конец интервала:");
		scanf("%d", &b);
		

		for (unsigned int i = 0; i < N; i++)
		{
			arr[i] *= a + rand() % ((b + 1) - a);
			printf("%d ", arr[i]);
			//if(arr[i] < 0)
				//negativeNumber++;
		}
		
		printf("\n");

		(*pindex) = 0;
		for (unsigned int i = 0; i < N; i++)
		{ 
				if(arr[i] < 0)
				{
					negativeArray[(*pindex)] = arr[i];
					//printf("%d ", negativeArray[index]);
					(*pindex)++;
				}
		}
		//int *negativeArray = new int[negativeNumber];
		//delete [] negativeArray;
		return negativeArray;
	}
	void main()
	{
		setlocale(LC_ALL,"Russian");
		const unsigned int lenght = 15;
		int mas[lenght];
		int negativeMas[lenght];
		int index;
		for(int i = 0; i<lenght;i++)
		{
			mas[i] = 1;
			printf("%d ",mas[i]);
		}
		processArray(mas,negativeMas,lenght,&index);
		for (unsigned int i = 0; i < index ; i++)
		{
			printf("%d ", negativeMas[i]);
		}
		printf("\n");
		printf(" л-во отрицательных чисел = %d ", index);
	system("pause");
	}
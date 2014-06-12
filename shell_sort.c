#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <stdint.h>


// Заполение массива рандомными числами
void filling_array(int *array, int N)
{
	int i;
	for (i=0; i<N; i++)
		array[i] = rand();
}

// Метод Шелла
void shell_sort(int *array, int N)
{
	int i=0, j=0, k=0, temp=0;
	for(k=N/2; k>0; k/=2)
		for(j=k; j<N; j++)
			for(i=j-k; i>=0; i-=k)
				if(array[i+k]>=array[i])
					break;
				else{
					temp = array[i];
					array[i]= array[i+k];
					array[i+k] = temp;
				}

}

void main()
{
	int *array;
	int i, N;

	setlocale(LC_ALL, "Russian");

	printf("Введите размер массива: ");
	scanf("%d", &N);

	array = (int *) malloc(N * sizeof(int));

	filling_array(array, N);

	printf("Исходный массив: ");
	for (i=0; i<N; i++)
		printf("%d ", array[i]);

	shell_sort(array, N);

	printf("\n\n");
	printf("Отсортированный массив: ");
	for (i=0; i<N; i++)
		printf("%d ", array[i]);

	free(array);
	array = NULL;

	_getch();
}

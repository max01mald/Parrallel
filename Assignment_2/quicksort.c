#include <math.h>
#include <stdlib.h>
#include <time.h>

void swap (int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	
}

int pivot(int beg, int length)
{
	return ((beg + length)/2);
}

void quicksort(int arr[], int beg, int length)
{
	
	if(beg < length)
	{
		int piv = pivot(beg, length);
	
		swap(&arr[beg],&arr[piv]);
	
		int comp = arr[beg];

		int i = beg+1;
		int j = length;
	
		while(i<=j)
		{
			while((i<=length) && (arr[i] <= comp))
				i++;
			while((j>=beg) && (arr[j] > comp))
				j--;
			if(i < j)
				swap(&arr[i], &arr[j]);
		}
	
		swap(&arr[beg],&arr[j]);
	
		quicksort(arr, beg, j-1);
		quicksort(arr, j+1, length);
	}
}

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%d\n",arr[i]);
	}
}

void random_fill(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		arr[i] = rand() % 100000;
	}
}

int main()
{
	const int SIZE = 2000000;
	int arr[SIZE];
	
	random_fill(arr, SIZE);
	
	printf("Before\n");
	
	print(arr, SIZE);
	
	clock_t begin = clock();
	
	quicksort(arr, 0, SIZE-1);
	
	clock_t end = clock();
    
	printf("AFTER\n");
    print(arr, SIZE);
    
    
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time %.20f\n",time_spent);
	
	
	
	return 0;
}

#include <stdio.h>

void array_transfer(int arr[], int arr2[], int sect, int length)
{
	int i=0; 
	
	
	while(i<length)
	{
		arr2[i] = arr[sect*length+i];
		i++;
	}

}

void array_merge(int arr[], int arr1[], int arr2[], int length1, int length2)
{
	int i=0;
	int j=0;
	
	while(i<length1)
	{
		arr[i] = arr1[i];
		i++;
	}
	
	while(j<length2)
	{
		arr[i] = arr2[j];
		i++;
		j++;
	}
}

void print(int arr[])
{
	for(int i=0; i<10; i++)
	{
		printf("%d\n",arr[i]);
	}
}

int main()
{
	int arr[10];
	int arr2[3] = {1,2,3};
	int arr3[7] = {4,5,6,7,8,9,10};
	
	array_merge(arr,arr2,arr3,3,7);
	
	print(arr);
	
	return 0;
}
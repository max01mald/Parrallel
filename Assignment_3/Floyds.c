#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int prob_node()
{
	double p = 0.5;
	
	int result = (p > ((double) rand()/RAND_MAX));
	
	return result;
}

void build_matrix (int N, int **arrF)
{
	int i = 0;
	int j = 0;
	
	int* arr = (int*) malloc(N*N*sizeof(int)); 
	
	while(i<N)
	{
		while(j<N)
		{
			if(i == j)
			{
				*(arr + i*N + j) = 0;
			}
			else if(prob_node())
			{
				*(arr + i*N + j) = 1 + rand() % 9;
				//printf("prob %d\n", *(arr + i*N +j));
			}
			else
			{
				*(arr + i*N + j) = -1;
			}
			j++;
		} 
		i++;
		j=0;
	}
	
	*arrF = arr;
	
}

void print_matrix(int N, int* arr)
{
	int i = 0;
	int j = 0;
	
	i=0;
	j=0;
	
	printf("\n");
	while(i<N)
	{
		while(j<N)
		{
			printf("%d " ,*(arr + i*N + j));
			
			j++;
		}
		printf("\n"); 
		j=0;
		i++;
	}

}

void floyd_matrix(int N, int*arr)
{
	int k = 0;
	int i = 0;
	int j = 0;
	
	int dik = 0;
	int dkj = 0;
	int dc = 0;
	
	while(k<N)
	{
		while(i<N)
		{
			while(j<N)
			{
				if(k != i || k != j)
				{
					if(*(arr + i*N + j) != 0)
					{
						dik = *(arr + i*N + k);
						dkj = *(arr + k*N + j);
						
						if(dik != 100 || dkj != 100)
						{
							dc = dik + dkj;
							
							if(dc < *(arr + i*N +j))
							{
								*(arr + i*N + j) = dc;
							}
						}
					}
				}
				j++;
			}
			j=0;
			i++;
		}
		i=0;
		k++;
		
		//printf("k is %d\n",k);
		//print_matrix(4,arr);
	}
}

void update(int* arr, int* row, int* col, int n, int cLine, char type)
{
        int i=0;
        int j=0;

        int dc = 0;

        while(i<n)
        {
                while(j<n)
                {
                        if(*(arr + i*n +j) != 0)
                        {
                                if(i != cLine && j != cLine && type == 'l')
                                {
                                        if(row[i] != 100 &&  col[j] != 100)
                                        {
                                                dc = row[i] + col[j];

                                                if(dc < *(arr + i*n +j))
                                                {
                                                        *(arr + i*n +j) = dc;
                                                }
                                        }
                                }
                                else if(i != cLine && type == 'c')
                                {
                                	if(row[i] != 100 &&  col[j] != 100)
                                    {
                                            dc = row[i] + col[j];

                                            if(dc < *(arr + i*n +j))
                                            {
                                                    *(arr + i*n +j) = dc;
                                            }
                                    }
                                }
                                else if(j != cLine && type == 'r')
                                {
                                	if(row[i] != 100 &&  col[j] != 100)
                                    {
                                            dc = row[i] + col[j];

                                            if(dc < *(arr + i*n +j))
                                            {
                                                    *(arr + i*n +j) = dc;
                                            }
                                    }
                                
                                }
                                else if(type == 'o')
                                {
                                	if(row[i] != 100 &&  col[j] != 100)
                                    {
                                            dc = row[i] + col[j];

                                            if(dc < *(arr + i*n +j))
                                            {
                                                    *(arr + i*n +j) = dc;
                                            }
                                    }
                                }
                        }
                        j++;
                }
                j=0;
                i++;
        }
}


int main()
{
	
	
	int arr[16] = {0,100,3,100,2,0,100,100,100,7,0,1,6,100,100,0};
	int arr2[64] = {0,1,2,3,4,5,6,7,1,2,3,4,5,6,7,8,2,3,4,5,6,7,8,9,3,4,5,6,7,8,9,10,4,5,6,7,8,9,10,1,5,6,7,8,9,10,1,2,6,7,8,9,10,1,2,3,7,8,9,10,1,2,3,4};
	
	int mini[16] = {6,4,2,3,7,3,5,4,2,10,10,10,3,10,10,10};
	
	int row[4] = {1,1,1,1};
	int col[4] = {1,1,1,1};
	
	//update(mini,col,row,4,2,'o');
	//print_matrix(4,mini);
	
	print_matrix(8,arr2);

	floyd_matrix(8,arr2);

	print_matrix(8,arr2);
	
	return 0;
	
}
#include <stdio.h>
#include <math.h>

void to_bin(char bin[], int size, int num)
{
        int i = 0;
        int b_num;

        size = size-1;

        while(size != -1)
        {
                b_num = pow(2,size);

                if(b_num <= num)
                {
                        bin[i] = '1';
                        num = num - b_num;
                }
                else
                {
                        bin[i] = '0';
                }
                i++;
                size--;
        }
}

void to_rank(char bin[], int size, int* rank)
{
        size = size-1;
        int i=0;
        int num = 0;
        while(size != -1)
        {
                if(bin[size] == '1')
                {
                        num += pow(2,i);
                        //printf("%f\n",pow(2,i));
                }
                size--;
                i++;
        }

        *rank = num;
}



int main()
{
	char bin[3];
	int rank;
		
	for(int i=0; i<8; i++)
	{
		to_bin(bin,3,i);
		to_rank(bin,3,&rank);
		
		printf("Index Rank %d Rank Rank %d\n",i,rank);
		
		
	}
	
	
	
	return 0;
}
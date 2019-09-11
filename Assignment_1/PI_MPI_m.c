#include "mpi.h"
#include <stdio.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

bool test(double x, double y, double r)
{
	double cX = r;
	double cY = r;
	double distance;
	 
	cX = fabs(cX - x);
	cY = fabs(cY - y);
	
	distance = pow(cX,2) + pow(cY,2);
	
	distance = sqrt(distance);
	
	if(distance > r)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}


int main( int argc, char *argv[] )
{
	double PIE;
	double box = 10;
	double radius = box/2;
	double distance;		
    double randomX;
    double randomY;
    
    double points = 100000;
    double count = 0;
    double count2 = 0;
    
    int p;
    int rank;
    int num;
    int amount;
    double time, time2;
    
    MPI_Comm children;
    
    //initialize MPI
    MPI_Init(&argc, &argv);
    //store the amount of processors in variable p
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    //discover the rank of the first process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    //Asks for the desired amount of child processors
    printf("Enter the number of children\n");
    scanf("%d", &amount);
    
    //Creates the child processors
    MPI_Comm_spawn("Child", MPI_ARGV_NULL, amount, MPI_INFO_NULL, 0, MPI_COMM_SELF, &children, MPI_ERRCODES_IGNORE);
	
	//Stores the total amount of processors in p
    p = amount + 1;
    
    //derives the necessary chunks to distribute
    num = points/(p);

    int i = 0;
	
	//sends the chunks to all the children using the children INTERCOMM
    while(i<amount)
    {
    	MPI_Send(&num, 1, MPI_INT, i, 0, children);
    	i++;
    }
    
    i = 0;
    
    //same as in c program
    while(i<num)
    {
    	randomX = fmod(rand(),box);
    	randomY = fmod(rand(),box);
    	
    	if(test(randomX, randomY, radius))
    	{
    		count += 1;
    	}
    	i++;
    	
    }
    
    int j =0;
	
	//master receives from all slaves
	while (j<(p-1))
	{
		//receives count and stores it in the local count
		MPI_Recv(&count2, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		printf("Master recieves count %d\n", count2);
		count += count2;
		j ++;
	}
	//displays the result
	PIE = count*4/points;
	printf("PI %f\n", PIE);
	
	//displays the elapsed time
	time2 = MPI_Wtime();
	printf("Time elapsed %.20f\n",time2-time);
   
    MPI_Finalize();
    return 0;
}

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
    
    //initialize MPI
    MPI_Init(&argc, &argv);
    //store the amount of processors in variable p
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    //discover the rank of the first process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    //divide the task evenly for all processes
    num = points/(p-1);
    int i = 0;
    
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
    
    //test if master or slave (not 0)
    if(rank == 0)
    {
        int j =0;
		
		//receive all the counts from other processes
        while (j<(p-1))
        {
        	//receive message
			MPI_Recv(&count2, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			
			printf("Master recieves count %d\n", count2);
			//add the received into the current count of the master process 
			count += count2;
			j ++;
        }
        //calculate Pi
        PIE = count*4/points;
        printf("PI %f", PIE);
    }
    else
    {
    	//Send the count to the master
    	MPI_Send(&count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    	printf("Slave sends count %d\n", count);
    }
    
    
    //Display the results
    printf("count %f\n", count);
    printf("PI %f\n", PIE);
    printf("Number of MPI %d\n", p);
    
    MPI_Finalize();
    return 0;
}

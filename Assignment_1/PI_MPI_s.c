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
    

	int size;
	//initialize MPI
    MPI_Init(&argc, &argv);
    //store the amount of processors in variable p
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    //discover the rank of the first process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
	MPI_Comm_remote_size(parent, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	//Slave receives chunk of work from master through parent COMM
    MPI_Recv(&num, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, parent, MPI_STATUS_IGNORE);

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
    //sends the count back to the master 
    MPI_Send(&count, 1, MPI_DOUBLE, 0, 0, parent);
	printf("Slave sends count %d\n", count);

	
	MPI_Finalize();
	return 0;
	
}
	
	
	
	
	
	
	
	
	
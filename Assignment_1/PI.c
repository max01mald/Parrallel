//#include "mpi.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0

//test to see if point given by x y are within the circle
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
    
    clock_t begin = clock();
    
    //generates points and tests, if within increment count by one
    for(int i=0; i<points; i++)
    {
    	randomX = fmod(rand(),box);
    	randomY = fmod(rand(),box);
    	
    	if(test(randomX, randomY, radius))
    	{
    		count += 1;
    	}
    	
    }
    
    PIE = 4*count/points;
    
    printf("count %f", count);
    printf("PI %f\n", PIE);
    
    clock_t end = clock();
    
    //calculate the difference between time at beginning and at end
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time %.20f\n",time_spent);
    
    return 0;
}

#include </usr/local/Cellar/tbb/2018_U5/include/tbb/parallel_for.h>
#include </usr/local/Cellar/tbb/2018_U5/include/tbb/task_scheduler_init.h>
#include </usr/local/Cellar/tbb/2018_U5/include/tbb/blocked_range.h>
#include </usr/local/Cellar/tbb/2018_U5/include/tbb/partitioner.h>
#include </usr/local/Cellar/tbb/2018_U5/include/tbb/task_group.h>

#include <stdio.h>
#include <iostream>




using namespace tbb;
using namespace std;

class ChangeArray
{
    int* array;
    
public:
    
    ChangeArray(int* a): array(a) {}
    
    
    void operator()(const blocked_range<int>&r) const
    {
        for(int i= r.begin(); i != r.end(); i++)
        {
            array[i] += 1;
        }
    }
};

void ChangeArrayParallel(int* a, int n)
{
    parallel_for(blocked_range<int>(0,n), ChangeArray(a), auto_partitioner());
}

int main()
{
    //task_scheduler_init init;
    
    int A[100];
    
    for(int i=0; i<100; i++)
    {
        A[i] = 0;
    }
    
    ChangeArrayParallel(A, 100);
    
    for(int i=0; i<100; i++)
    {
        cout << A[i] << endl;
    }
    
    return 0;
    
}


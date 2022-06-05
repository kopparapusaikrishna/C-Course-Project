#include "Sort.h"

Sort::Sort()
{

}

Sort::Sort(std::vector<Degree> Arr):arr(Arr)
{
    Sort::Sorting();
}

std::vector<Degree> Sort::Sorting()
{
    int n=arr.size();
    int i, j;  
    for (i = 0; i < n-1; i++)
    {        
        for (j = 0; j < n-i-1; j++)  
        {   
            if (arr[j].getDegree() > arr[j+1].getDegree())  
            { 
                Degree temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }  
    return arr;
}
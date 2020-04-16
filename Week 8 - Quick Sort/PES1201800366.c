#include <stdio.h>
#include "quickSort.h"
ptrPair divide(int *a, int n)
{
    int pivot = getPartitionIndex(a,n);
    ptrPair p;
    p.first = a;
    p.firstLen = pivot+1;
    p.second = a+pivot+1;
    p.secondLen = n-pivot-1;
    return p;
}

int getPartitionIndex(int *a, int n)
{
    int pivot = a[0];
    int i=-1, j=n, temp;
    while(1)
    {
        do{
            i++;
        } while(a[i]<pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i>=j)
            return j;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void conquer(int *a, int n)
{
    if(n>1)
    {
        ptrPair pivot = divide(a,n);
        conquer(pivot.first,pivot.firstLen);
        conquer(pivot.second,pivot.secondLen);
    }
}

void quickSort(int *a, int n)
{
    conquer(a,n);
}

int isSorted(int *a, int n)
{
    for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			return 0;
	}
	return 1;
}
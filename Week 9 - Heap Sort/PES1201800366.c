#include <stdio.h>
#include "heapSort.h"
#include <stdlib.h>
Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a = (int*)malloc(n*sizeof(int));
    h.a = a;
    h.size = n;
    for(int i=n/2-1;i>=0;i--)
        maxHeapify(h,i);
    h.size = n;
    return h;
}

void maxHeapify(Heap h, int idx)
{
    int largest = idx;  
    int l = 2*idx + 1; 
    int r = 2*idx + 2; 
    int n = h.size;

    if (l < n && h.a[l] > h.a[largest]) 
        largest = l; 
  
    if (r < n && h.a[r] > h.a[largest]) 
        largest = r; 

    if (largest != idx) 
    { 
        int temp = h.a[largest];
        h.a[largest] = h.a[idx];
        h.a[idx] = temp;
        maxHeapify(h,largest); 
    } 
}

void heapSort(int *const a, int n)
{
    Heap h = buildMaxHeap(a,n);
    h.size--;
    for(int i=n-1;i>=0;i--)
    {
        int temp = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = temp;
        maxHeapify(h,0);
        h.size--;
    }
}

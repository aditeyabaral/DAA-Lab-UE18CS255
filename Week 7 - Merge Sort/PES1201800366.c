#include "mergeSort.h"
#include <stdlib.h>
#include <stdio.h>
void mergeSortedHalfs(int *a, int start, int mid, int end)
{
    int i,j,k;
    int len1 = mid-start+1;
    int len2 = end-mid;
    int *temp1 = (int*)malloc(sizeof(int)*len1);
    int *temp2 = (int*)malloc(sizeof(int)*len2);
    for(int i=0;i<len1;i++)
        temp1[i] = a[start+i];
    for(int j=0;j<len2;j++)
        temp2[j] = a[mid+1+j];
    k = start, i = 0, j = 0;
    while(i<len1 && j<len2)
    {
        if(temp1[i]<temp2[j])
        {
            a[k] = temp1[i];
            i++;
        }
        else
        {
            a[k] = temp2[j];
            j++;
        }
        k++;
    }
    while(i<len1)
    {
        a[k] = temp1[i];
        i++;
        k++;
    }
    while(j<len2)
    {
        a[k] = temp2[j];
        j++;
        k++;
    }
    free(temp1);
    free(temp2);
}
void mergeSort(int *a, int start, int end)
{
    if(start<end)
    {
        int mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        mergeSortedHalfs(a,start,mid,end);
    } 
}
void insertionSort(int *a, int start, int end)
{
    int j,temp,n = end-start+1;
    for (int i=1;i<n;i++)
    {
        j = i-1;
        temp = a[i];
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
void selectiveMergeSort(int *a, int start, int end, int parameter)
{
    if((end-start+1)>parameter)
        mergeSort(a,start,end);
    else
        insertionSort(a,start,end);
}
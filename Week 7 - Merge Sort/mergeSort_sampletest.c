#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mergeSort.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[])
{
    const int original[] = {5, 1, 4, 2, 8, 9};
    int n = sizeof(original) / sizeof(original[0]);
    int a[n];
    memcpy(a, original, sizeof(original));

    for (int i = 0; i < n; i++) // PRINT INITIAL ARRAY
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int result;
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    mergeSort(a, 0, n - 1);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    result = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            result = 0;
            break;
        }
    }

    if (1 == result)
    {
        printf("%lf sec spent on test1 of mergeSort()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of mergeSort()\n");
    }
    for (int i = 0; i < n; i++) // SORTED ARRAY ARRAY
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    memcpy(a, original, sizeof(original));
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    selectiveMergeSort(a, 0, n - 1, 2);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    result = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > a[i + 1])
        {
            result = 0;
            break;
        }
    }
    if (1 == result)
    {
        printf("%lf sec spent on test1 of selectiveMergeSort()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of selectiveMergeSort()\n");
    }

    for (int i = 0; i < n; i++) // SORTED ARRAY
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}

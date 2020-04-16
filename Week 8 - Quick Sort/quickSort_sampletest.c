#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "quickSort.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);
int _isSorted(int *a, int n);

int main(int argc, char const *argv[])
{
    int a[] = {5, 1, 4, 2, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) // PRINT INITIAL ARRAY
        printf("%d ", a[i]);
    printf("\n");

    int result;
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    quickSort(a, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (1 == _isSorted(a, n))
    {
        printf("%lf sec spent on test1 of quickSort()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of quickSort()\n");
    }

    for (int i = 0; i < n; i++) // PRINT FINAL ARRAY
        printf("%d ", a[i]);
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

int _isSorted(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

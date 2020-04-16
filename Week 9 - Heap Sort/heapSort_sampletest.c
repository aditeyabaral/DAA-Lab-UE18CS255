#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "heapSort.h"

double time_elapsed(struct timespec start, struct timespec end);
int _isSorted(int *a, int n);
void printArray(int *a, int n);

int main(int argc, char const *argv[])
{
    int a[] = {5, 1, 4, 2, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    struct timespec start, end; /* timestamps */

    printArray(a, n); /* PRINT INITIAL ARRAY */

    clock_gettime(CLOCK_REALTIME, &start); /* Start timestamp */
    heapSort(a, n);
    clock_gettime(CLOCK_REALTIME, &end); /* Start timestamp */
    if (1 == _isSorted(a, n))
    {
        printf("%lf sec spent on test1 of heapSort()\n", time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of heapSort()\n");
    }

    printArray(a, n); /* PRINT FINAL ARRAY */
    return 0;
}

/* Time elapsed from 'start' to 'end' in seconds */
double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);           /* diff of tv_sec */
    t += (end.tv_nsec - start.tv_nsec) * 1e-9; /* add diff of tv_nsec too */
    return t;
}

int _isSorted(int *a, int n)
{
    for (int i = 0; i < n - 1; ++i)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

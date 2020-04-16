#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

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
    result = numSwaps(a, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (2 == result)
    {
        printf("%lf sec spent on test1 of numSwaps()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of numSwaps()\n");
        printf("numSwaps: %d (expected value: 2)\n", result);
    }

    memcpy(a, original, sizeof(original));
    bubbleSort(a, n);
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    result = isSorted(a, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (1 == result)
    {
        printf("%lf sec spent on test1 of isSorted()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of isSorted()\n");
        printf("isSorted: %d (expected value: 1)\n", result);
    }

    memcpy(a, original, sizeof(original));
    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    result = numBubblePasses(a, n);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (2 == result)
    {
        printf("%lf sec spent on test1 of numBubblePasses()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of numBubblePasses()\n");
        printf("numBubblePasses: %d (expected value: 2)\n", result);
    }

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

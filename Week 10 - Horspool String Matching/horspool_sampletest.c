#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#include "horspool.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[])
{
    // int a[7] = {10, 23, 30, 23, 50, 60};

    char *text = "AABAACAADAABAAABAA";
    char *pattern = "AABA";
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    Result *result = horspoolStringMatch(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (result->firstOccurrence != 0)
    {
        printf("FAILED test1 of horspoolStringMatch() - first occurrence offset incorrect\n");
        printf("first occurrence offset: %d (expected value: 0)\n", result->firstOccurrence);
    }

    else if (result->lastOccurrence != 13)
    {
        printf("FAILED test1 of horspoolStringMatch() - last occurrence offset incorrect\n");
        printf("last occurrence offset: %d (expected value: 13)\n", result->lastOccurrence);
    }

    else if (result->numOccurrences != 3)
    {
        printf("FAILED test1 of horspoolStringMatch() - number of occurrence incorrect\n");
        printf("numOccurrences : %d (expected value: 3)\n", result->numOccurrences);
    }

    else if (result->charactersCompared != 18)
    {
        printf("FAILED test1 of horspoolStringMatch() - number of characters compared incorrect\n");
        printf("charactersCompared: %d (expected value: 18)\n", result->charactersCompared);
    }

    else
    {
        printf("%lf sec spent on test1 of horspoolStringMatch()\n",
               time_elapsed(start, end));
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
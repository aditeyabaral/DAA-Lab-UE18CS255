#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sm.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[])
{
    // int a[7] = {10, 23, 30, 23, 50, 60};

    char *text = "AABAACAADAABAAABAA";
    char *pattern = "AABA";
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int offset = searchFirstOccurrence(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (offset == 0)
    {
        printf("%lf sec spent on test1 of searchFirstOccurrence()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of searchFirstOccurrence()\n");
        printf("offset: %d (expected value: 0)\n", offset);
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    offset = searchLastOccurrence(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (offset == 13)
    {
        printf("%lf sec spent on test1 of searchLastOccurrence()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of searchLastOccurrence()\n");
        printf("offset: %d (expected value: 13)\n", offset);
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int count = numOccurrences(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (count == 3)
    {
        printf("%lf sec spent on test1 of numOccurrences()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of numOccurrences()\n");
        printf("offset: %d (expected value: 3)\n", offset);
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    count = charactersCompared(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (count == 35)
    {
        printf("%lf sec spent on test1 of charactersCompared()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of charactersCompared()\n");
        printf("count: %d (expected value: 35)\n", offset);
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    pattern = "AABAX";
    count = longestPrefix(pattern, text);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if (count == 4)
    {
        printf("%lf sec spent on test1 of longestPrefix()\n",
               time_elapsed(start, end));
    }
    else
    {
        printf("FAILED test1 of longestPrefix()\n");
        printf("length: %d (expected value: 4)\n", offset);
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ss.h"

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[]) {
    int a[7] = {10, 23, 30, 23, 50, 60};
    struct timespec start, end; //timestamps

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int offset = searchFirstOccurrence(a, 6, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(offset == 1) {
        printf("%lf sec spent on test1 of searchFirstOccurrence()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of searchFirstOccurrence()\n");
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    offset = searchLastOccurrence(a, 6, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(offset == 3) {
        printf("%lf sec spent on test1 of searchLastOccurrence()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of searchLastOccurrence()\n");
    }

    clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
    int count = numOccurrences(a, 6, 23);
    clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
    if(count == 2) {
        printf("%lf sec spent on test1 of numOccurrences()\n",
            time_elapsed(start, end));
    } else {
        printf("FAILED test1 of numOccurrences()\n");
    }
    return 0;
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec); //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}

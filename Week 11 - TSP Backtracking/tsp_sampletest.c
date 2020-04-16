#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tsp.h"

#define N 4

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

int main(int argc, char const *argv[])
{
	int graph[N][N] = {{0, 10, 15, 20},
					   {10, 0, 35, 25},
					   {15, 35, 0, 30},
					   {20, 25, 30, 0}};
	int result;
	struct timespec start, end;

	// Test case 1
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	result = tspBackTrack(N, graph);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
	if (80 == result)
	{
		printf("%lf sec spent on test1 of tsp()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test1 of tsp()\n");
		printf("tsp: %d (expected value: %d)\n", result, 80);
	}

	// Test case 2
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	int *a = printPath(N, graph);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

	int expA[] = {0, 1, 3, 2};
	result = memcmp(a, expA, N * sizeof(int)); // Compare the two arrays
	if (0 == result)
	{
		printf("%lf sec spent on test1 of printPath()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test1 of printPath()\n");
		printf("printPath: ");
		for (int i = 0; i < N; ++i)
			printf("%d ", a[i]);

		printf(" (expected path: ");
		for (int i = 0; i < N; ++i)
			printf("%d ", expA[i]);
		printf(")\n");
	}
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				  //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}
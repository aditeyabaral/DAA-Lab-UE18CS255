#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "graphSearch.h"

#define N 5

//Finds time elapsed from start to end in seconds
double time_elapsed(struct timespec start, struct timespec end);

bool structCmp(Result lhs, Result rhs)
{
	return (lhs.maxHouses == rhs.maxHouses && lhs.numDeliveryFrogs == lhs.numDeliveryFrogs);
}

int main(int argc, char const *argv[])
{
	int graph[N][N] = {{0, 1, 1, 1, 0},
					   {1, 0, 0, 0, 0},
					   {1, 0, 0, 0, 0},
					   {1, 0, 0, 0, 1},
					   {0, 0, 0, 1, 0}};

	int res;
	Result answers;
	struct timespec start, end;

	// Test case 1
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	res = isTree(N, graph);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
	if (true == res)
	{
		printf("%lf sec spent on test1 of isTree()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test1 of isTree()\n");
		printf("isTree: %d (expected value: %d)\n", res, true);
	}

	// Test case 2
	graph[2][1] = 1;
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	res = isTree(N, graph);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp
	if (false == res)
	{
		printf("%lf sec spent on test2 of isTree()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test2 of isTree()\n");
		printf("isTree: %d (expected value: %d)\n", res, false);
	}

	int safeSeq[N][N] = {{0, 1, 1, 0, 0},
						 {1, 0, 0, 0, 0},
						 {1, 0, 0, 0, 0},
						 {0, 0, 0, 0, 1},
						 {0, 0, 0, 1, 0}};

	// Test case 3
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	answers = pepesAnswers(N, safeSeq);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

	if (2 == answers.numDeliveryFrogs && 3 == answers.maxHouses)
	{
		printf("%lf sec spent on test1 of pepesAnswers()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test1 of pepesAnswers()\n");
		printf("pepesAnswers: %d %d (expected: %d %d)\n", answers.numDeliveryFrogs, answers.maxHouses, 2, 3);
	}

	// Test case 4
	clock_gettime(CLOCK_REALTIME, &start); //Start timestamp
	answers = pepesAnswersWithK(N, safeSeq, 1);
	clock_gettime(CLOCK_REALTIME, &end); //Start timestamp

	if (3 == answers.numDeliveryFrogs && 2 == answers.maxHouses)
	{
		printf("%lf sec spent on test1 of pepesAnswersWithK()\n",
			   time_elapsed(start, end));
	}
	else
	{
		printf("FAILED test1 of pepesAnswersWithK()\n");
		printf("pepesAnswersWithK: %d %d (expected: %d %d)\n", answers.numDeliveryFrogs, answers.maxHouses, 2, 3);
	}
	return 1;
}

//Time elapsed from 'start' to 'end' in seconds
double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				  //diff of tv_sec
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
	return t;
}
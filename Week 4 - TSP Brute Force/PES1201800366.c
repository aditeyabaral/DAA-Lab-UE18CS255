#include <limits.h>
#include "tsp.h"
#include <stdlib.h>
#include <limits.h>
int tsp(int n, int graph[][n])
{
	int cost = 0, mincost = INT_MAX;
	int *nodes = (int*)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;i++)
		nodes[i] = i;
	while(1)
	{
		cost = getCost(n,graph,nodes);
		if (cost<mincost)
			mincost = cost;
		if(!get_next_permutation(nodes,n))
			break;
	}
	return mincost;
}

int* printPath(int n, int graph[][n])
{
	int* path = (int*)malloc(sizeof(int)*(n+1));
	int cost = 0, mincost = INT_MAX;
	int *nodes = (int*)malloc(sizeof(int)*(n+1));
	for(int i=0;i<n;i++)
		nodes[i] = i;
	while(1)
	{
		cost = getCost(n,graph,nodes);
		if (cost<mincost)
		{
			mincost = cost;
			for(int i=0;i<n;i++)
				path[i] = nodes[i];
			path[n] = nodes[0];
		}
		if(!get_next_permutation(nodes,n))
			break;
	}
	return path;
}

int getCost(int n, int graph[][n], int *P)
{
	int cost = 0;
	for(int i = 0;i<n-1;i++)
		cost+=graph[P[i]][P[i+1]];
	cost+=graph[P[n-1]][P[0]];
	return cost;
}

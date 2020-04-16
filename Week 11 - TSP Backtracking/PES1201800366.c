#include "tsp.h"
#include <stdio.h>
#include <stdlib.h>

int* finalpath;
int* path;

int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost){
    if(currentCost > minCost)
        return minCost;
    visited[v] = true;
    nodesVisited++;
    path[nodesVisited - 1] = v;
    int i;
    if(nodesVisited == n){
        visited[v] = false;
        if(graph[v][0] + currentCost < minCost){
            int j;
            for(j = 0; j < n; j++)
                finalpath[j] = path[j];
            path[nodesVisited - 1] = 0;
            return (graph[v][0] + currentCost);
        }
        return minCost;
    }
    for(i = 0; i < n; i++){
        if(!visited[i]){
            minCost = tspBacktrackRecursive(i, n, graph, visited, nodesVisited, currentCost + graph[v][i], minCost);
        }
    }
    path[nodesVisited - 1] = 0;
    visited[v] = false; 
    return minCost;
}

int tspBackTrack(int n, int graph[][n]){
    bool* visited = (bool*)calloc(n, sizeof(bool));
    finalpath = (int*)calloc(n, sizeof(int));
    path = (int*)calloc(n, sizeof(int));
    return tspBacktrackRecursive(0, n, graph, visited, 0, 0, __INT_MAX__);
}

int *printPath(int n, int graph[][n]){
    return finalpath;
}
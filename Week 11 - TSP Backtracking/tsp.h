#include <stdbool.h>

/**
 * Starting from node 0 recurisivly compute and return the minimum cost.*
 * graph[i][j] is the cost moving from node i to node j.*
 * At every function call currentCost contains the cost of the path traversed till now,*
 * nodesVisited is the number of visited nodes in the current path.*
 * When a path is completed commpare its cost to mincost, return minimum of both, backtrack*
 * and compute the costs of the other paths, return the minimum of all of them.*
 * If at any stage the currentCost becomes greater than the mincost backtrack from that point.
 */
int tspBacktrackRecursive(int v, int n, int graph[][n], bool *visited, int nodesVisited, int currentCost, int minCost);

/**
 * Compute the minimum cost required to visit all nodes using the tspBacktrackRecursive() function 
 */
int tspBackTrack(int n, int graph[][n]);

/**
 * Print the minimum cost path, you use a static function similar to tspBacktrackRecursive()
 */
int *printPath(int n, int graph[][n]);
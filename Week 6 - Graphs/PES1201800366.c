#include "graphSearch.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false
/*
Do DFS from every vertex. (please read DFS here).
During DFS, for any current vertex ‘x’ (currently visiting vertex) if there an adjacent vertex ‘y’ is present which is already visited 
and ‘y’ is not a direct parent of ‘x’ then there is a cycle in graph.
*/
bool isCyclic(int u, bool visited[], int parent, int n, const int graph[][n]) 
{
	visited[u] = true;
	for(int v = 0; v<n; v++)
	{
		if(graph[u][v])
		{
			if(!visited[v])
			{
				if(isCyclic(v, visited, u, n, graph))
				{
					return true;
				}
			}
			else if(v != parent)
			{ //when adjacent vertex is visited but not parent
				return true; //there is a cycle
			}
		}
	}
	return false;
}
	
bool isTree(int n, const int graph[][n])
{
	bool visited[n];
	for (int i = 0; i < n; i++)
	    visited[i] = false;
	if (isCyclic(0, visited, -1, n, graph))
	    return false;
	for (int i = 0; i < n; i++)
        if (!visited[i])
            return false;
	return true;
}

int dfs_frog(int n, const int graph[][n], int v, bool visited[], int k)
{
    int houses = 1;
    visited[v]=1;
    for(int i=0;i<n;++i)
    {
        if(visited[i]==0 && graph[v][i] && abs(v-i) <=k)
            houses+=dfs_frog(n, graph, i, visited, k);
    }
    return houses;
}



// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n])
{
    Result ans;
    ans.maxHouses=-1;
    ans.numDeliveryFrogs=0;
    bool visited[n];
    int houses=0;
    for(int i=0;i<n;++i)
        visited[i]=false;
    for(int i = 0; i<n;++i)
    {
        if(!visited[i])
        {
            houses = dfs_frog(n, safeSeq, i, visited, INT_MAX);
            if(houses > ans.maxHouses)
                ans.maxHouses=houses;
            ans.numDeliveryFrogs+=1;
        }
    }
    return ans;
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
    Result ans;
    ans.maxHouses=-1;
    ans.numDeliveryFrogs=0;
    bool visited[n];
    int houses=0;
    for(int i=0;i<n;++i)
        visited[i]=false;
    for(int i = 0; i<n;++i)
    {
        if(!visited[i])
        {
            houses = dfs_frog(n, safeSeq, i, visited, k);
            if(houses > ans.maxHouses)
                ans.maxHouses=houses;
            ans.numDeliveryFrogs+=1;
        }
    }
    return ans;
}

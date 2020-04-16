// Header file for graph search
#include <stdbool.h>

typedef struct {
    int numDeliveryFrogs;
    int maxHouses;
} Result;

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false
bool isTree(int n, const int graph[][n]);

// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n]);

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k);

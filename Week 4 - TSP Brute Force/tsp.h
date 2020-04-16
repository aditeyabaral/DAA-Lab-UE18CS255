// Header file for travelling salesman problem

//Finds a solution for the traveling salesman problem
//Returns the cost of a min-cost Hamiltonian circuit of the given
//directed complete graph with n vertices in the form a cost matrix.
int tsp(int n, int graph[][n]);

// Returns an array of size n, 
// starting at city_0 (that is the first node) 
// traversing the path with min-cost
// Note: Return the path which is lexicographically smaller in case two paths have the same cost
int* printPath(int n, int graph[][n]);

// Given a permutation of path - P[], 
// Return the cost from the starting city through the path and back
// P[0] -> P[1] -> ... -> P[n-1] -> P[0]
int getCost(int n, int graph[][n], int *P);

// Get the next permutation in lexicographical order
// Returns 0 if there is no permutation which lexicographically bigger 
// Implemented in tsp_sampletest.c and tsp_tests.c
// Not to be implemented as a part of lab session
int get_next_permutation(int *permutation, int n);

// Merges two sorted halfs of an array into a single sorted array
void mergeSortedHalfs(int *a, int start, int mid, int end);

// Implement merge sort using the mergeSortedHalfs() declared above
// start is the index of the first element of the array
// end is the index of the last element of the array
void mergeSort(int *a, int start, int end);

// Implement insertion sort
// n - number of elements in the array
void insertionSort(int *a, int start, int end);

// Implement a function which applies merge sort only if
// size of the array is larger than that of parameter
// if not apply insertion sort.
// Use mergeSortedHalfs() and insertionSort() declared above to do the same.
void selectiveMergeSort(int *a, int start, int end, int parameter);

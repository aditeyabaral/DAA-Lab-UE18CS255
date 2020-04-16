// Header file for the implementation of Bubble sort and
// Selection sort algorithms

// Check if an array is sorted.
// Return 1 if the array is sorted, 0 otherwise.
int isSorted(int *a, int n);

//Consider an array a[0] to a[n-1]. 
//For each element a[i], which is greater than or equal to all the elements
// from a[0] thru a[i-1], move a[i] to a[k] where all the elements from a[i+1]
// thru a[k] are less than a[i] and either k=n-1 or a[k+1] >= a[i].
//Essentially, one pass of bubbling larger elements from left to right.
//Eg: Array 1 4 3 2 6 5 is transformed to 1 3 2 4 5 6.
void bubblePass(int *a, int n);

//Implement Bubble sort using bubblePass() declared above.
void bubbleSort(int *a, int n);

//Find the minimum number of BubblePasses required to sort by Bubble sort
// algorithm. Note that a sorted array does not require any bubblePasses. 
//Use isSorted() function before calling BubblePass().
int numBubblePasses(int *a, int n);

//Find the offset(index) of the maximum element in an array.
//In case of multiple occurrences of the maximum element,
// return the largest offset (or rightmost index).
int maxIndex(int *a, int n);

//Consider an array a[0] to a[n-1].
//Let i be the largest offset of the maximum element in the array.
//Swap a[i] with a[n-1] if i < n-1.
//Use maxIndex() declared above.
void swapWithMax(int *a, int n);

//Implement Selection sort using maxIndex() and swapWithMax() declared above.
void selectionSort(int *a, int n);

//Find the number of swaps in selectionSort() declared above.
int numSwaps(int *a, int n);

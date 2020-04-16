typedef struct
{
    int firstOccurrence;
    int lastOccurrence;
    int numOccurrences;
    int charactersCompared;
} Result;

/*
* Given the pattern fill the shift table used by Horspool's algorithm
* Table[pattern[i]] indicates the amount to be shifted when there is mismatch
* Initialize all the elements of Table with the length of the pattern    
* The table size can be 256
*/
int *buildShiftTable(char *pattern);

/*
* Implement the horspool's string matching algoritm using the buildShiftTable()
  function to build the shift table.
* Compute offset of the first and last occurence of pattern in the text,
  In case of no occurrences of the pattern the value should be set to -1.
* Compute the number of occurences of the pattern in the text.
* Compute the number of characters compared while finding all occurences of the pattern in the given text
* Characters must be matched from left to right
*/

Result *horspoolStringMatch(char *pattern, char *text);

void display(int*);
// Header file for the implementation of Naive algorithm for String Matching

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchFirstOccurrence(char *pattern, char *text);

// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text);

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text);

// Find the length of longest prefix of the pattern that matches a substring of the pattern
int longestPrefix(char *pattern, char *text);

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text);
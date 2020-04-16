#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "horspool.h"

int *buildShiftTable(char *pattern)
{
    int len = strlen(pattern);
    int *table = (int*)malloc(sizeof(int)*256);
    for (int i=0;i<256;i++)
        table[i] = len;
    for(int i=0;i<len-1;i++)
    {
        int pos = (int)pattern[i];
        int offset = len-1-i;
        table[pos] = offset;
    }
    return table;
}

Result *horspoolStringMatch(char *pattern, char *text)
{
    Result *r = (Result*)malloc(sizeof(Result));
    r->charactersCompared = r->numOccurrences = 0;
    r->firstOccurrence = r->lastOccurrence = -1;
    int *table = buildShiftTable(pattern);
    
    int n = strlen(text);
    int m = strlen(pattern);
    int i = m-1;
    int k;
    
    while(i<n)
    {
    	k = 0;
    	while((k<m) && (pattern[m-1-k]==text[i-k]))
    	{
    		k++;
    		r->charactersCompared+=1;
    	}
    	r->charactersCompared+=1;
    	if(k==m)
    	{
    		r->numOccurrences+=1;
    		if(r->numOccurrences==1)
    			r->firstOccurrence = i-m+1;
			r->lastOccurrence = i-m+1;
			i+=m;
		}
		else
			i=i+table[(int)text[i]];
	} 
    free(table);
    return r;
}

void display(int *table)
{
    for(int i = 0;i<256;i++)
        printf("%d ",table[i]);
    printf("\n");
}

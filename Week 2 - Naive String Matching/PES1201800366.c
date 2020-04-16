#include <string.h>
int searchFirstOccurrence(char *pattern, char *text)
{
        int pos = -1;
        int m = strlen(text), n = strlen(pattern);
        for (int i=0;i<(m-n);i++)
        {
                if (text[i] == pattern[0])
                {
                        pos = i;
                        for(int j=1;j<n;j++)
                        {
                                if(pattern[j]!=text[i+j])
                                {
                                        pos = -1;
                                        break;
                                }
                        }
                        if(pos!=-1)
                                return pos;  
                }
        }
        return pos;
}
                                        
int searchLastOccurrence(char *pattern, char *text)
{
        int pos = -1, temp;
        int m = strlen(text), n = strlen(pattern);
        for (int i=0;i<(m-n);i++)
        {
                if (text[i] == pattern[0])
                {
                        temp = i;
                        for(int j=1;j<n;j++)
                        {
                                if(pattern[j]!=text[i+j])
                                {
                                        temp = -1;
                                        break;
                                }
                        }
                        if(temp!=-1)
                                pos = temp; 
                }
        }
        return pos;
}

int numOccurrences(char *pattern, char *text)
{
        int ctr = 0, flag = -1;
        int m = strlen(text), n = strlen(pattern);
        for (int i=0;i<(m-n);i++)
        {
                if (text[i] == pattern[0])
                {
                        flag = 1;
                        for(int j=1;j<n;j++)
                        {
                                if(pattern[j]!=text[i+j])
                                {
                                        flag = -1;
                                        break;
                                }
                        }
                        if(flag==1)
                                ctr++; 
                }
        }
        return ctr;
}

int longestPrefix(char *pattern, char *text)
{
        int ctr = 0, max = 0;
        int m = strlen(text), n = strlen(pattern);
        for (int i=0;i<(m-n);i++)
        {
                if (text[i] == pattern[0])
                {
                        ctr = 1;
                        for(int j=1;j<n;j++)
                        {
                                if (pattern[j]==text[i+j])
                                        ctr++;
                                else
                                        break;
                        }
                        if(ctr>max)
                                max = ctr; 
                }
        }
        return max;
}
int charactersCompared(char *pattern, char *text)
{
        int ctr = 0;
        int m = strlen(text), n = strlen(pattern);
        for (int i=0;i<(m-n);i++)
        {
                        for(int j=0;j<n;j++)
                        {
                                ctr++;
                                if (pattern[j]!=text[i+j])
                                {
                                        break;
                                }
                        }
        }
        return ctr+1;
}


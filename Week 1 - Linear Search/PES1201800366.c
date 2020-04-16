int searchFirstOccurrence(int arr[], int n, int key)
{
        for(int i=0;i<n;i++)
        {
                if(arr[i]==key)
                        return i;
        }
        return -1;
}

int searchLastOccurrence(int arr[], int n, int key)
{
        int pos = -1;
        for(int i=0;i<n;i++)
        {
                if(arr[i]==key)
                        pos = i;
        }
        return pos;
}

int numOccurrences(int arr[], int n, int key)
{
        int ctr = 0;
        for(int i=0;i<n;i++)
                ctr+=(arr[i]==key);
        return ctr;
}

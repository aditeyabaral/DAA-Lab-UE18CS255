#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "session5_sort.h"
int main()
{
    char inputfiles[11][30] = {"session5_sort_ip1.txt",
                        "session5_sort_ip2.txt",
                        "session5_sort_ip3.txt",
                        "session5_sort_ip_rand032k.txt",
                        "session5_sort_ip_rand064k.txt",
                        "session5_sort_ip_rand096k.txt",
                        "session5_sort_ip_rand128k.txt",
                        "session5_sort_ip_rand160k.txt",
                        "session5_sort_ip_rand192k.txt",
                        "session5_sort_ip_rand224k.txt",
                        "session5_sort_ip_rand256k.txt"};

    char outputfiles[11][30] = {"session5_sort_op1.txt",
                        "session5_sort_op2.txt",
                        "session5_sort_op3.txt",
                        "session5_sort_op_rand032k.txt",
                        "session5_sort_op_rand064k.txt",
                        "session5_sort_op_rand096k.txt",
                        "session5_sort_op_rand128k.txt",
                        "session5_sort_op_rand160k.txt",
                        "session5_sort_op_rand192k.txt",
                        "session5_sort_op_rand224k.txt",
                        "session5_sort_op_rand256k.txt"};
    long int n, serialnum;
    int score;
    struct timespec start[5], end[5];
    double elapsed;
    FILE* data = fopen("Stats.csv","w");
    char outputline[50];
    char s[50];
    strcpy(outputline,"N,Insertion Sort,Bubble Sort,Selection Sort\n");
    for(int i=0;i<11;i++)
    {
        FILE* fp1 = fopen(inputfiles[i],"r");
        FILE* fp2 = fopen(outputfiles[i],"r");
        n = atol(fgets(s,50,fp1));
        Record* A = (Record*)malloc(sizeof(Record)*n);
        Record* B = (Record*)malloc(sizeof(Record)*n);
        Record* C = (Record*)malloc(sizeof(Record)*n);
        int ctr = 0;
        
        while(fgets(s,50,fp1)!=NULL)
        {
            char* token = strtok(s," ");
            serialnum = atol(token);
            token = strtok(NULL," ");
            score = atol(token);

            A[ctr].serialnumber = serialnum;
            A[ctr].score = score;

            B[ctr].serialnumber = serialnum;
            B[ctr].score = score;

            C[ctr].serialnumber = serialnum;
            C[ctr].score = score;
            
            ctr++;
        }
        
        long int expected_swaps[5];
        long int temp1;
        float temp2;
        float expected_time[5];
        int pos = 0;
        while(fgets(s,50,fp2)!=NULL)
        {
            char* token = strtok(s," ");
            token = strtok(NULL," ");
            token = strtok(NULL," "); 
            expected_swaps[pos] = atol(token);
            token = strtok(NULL," ");
            expected_time[pos] = atof(token);
            pos++;
        }
        
		clock_gettime(CLOCK_REALTIME, &start[0]);
        long int ctr1 = InsertionSort(A,n);
        clock_gettime(CLOCK_REALTIME, &end[0]);
        
        clock_gettime(CLOCK_REALTIME, &start[1]);
        long int ctr2 = BubbleSort(B,n);
        clock_gettime(CLOCK_REALTIME, &end[1]);
        
        clock_gettime(CLOCK_REALTIME, &start[2]);
        long int ctr3 = SelectionSort(C,n);
        clock_gettime(CLOCK_REALTIME, &end[2]);
        
        char temp_time[20];
        sprintf(temp_time,"%ld",n);
        strcat(temp_time,",");
        strcat(outputline,temp_time);
        strcpy(temp_time,"");
        for(int i=0;i<3;i++)
        {
        	elapsed = time_elapsed(start[i], end[i]);
        	sprintf(temp_time,"%f",elapsed);
        	strcat(temp_time,",");
        	strcat(outputline,temp_time);
        	strcpy(temp_time,"");
        }
        strcat(outputline,"\n");
        fwrite(outputline,strlen(outputline),1,data);
		strcpy(outputline,"");
		
        int flag1,flag2,flag3,flag4,flag5;
        flag1 = (ctr1==expected_swaps[0]);
        flag2 = (ctr2==expected_swaps[1]);
        flag3 = (ctr3==expected_swaps[2]);
        //flag4 = (ctr3==expected_swaps[3])
        //flag5 = (ctr3==expected_swaps[4])
            
        if(flag1 && flag2 && flag3)
        	printf("Test Case : %d PASSED\n",i+1);
        else
        {
        	printf("Test Case : %d FAILED\n",i+1);
        	if (!flag1)
        		printf("Insertion Sort: Expected: %ld, Your answer: %ld\n",expected_swaps[0],ctr1);
        	if(!flag2)
        		printf("Bubble Sort: Expected: %ld, Your answer: %ld\n",expected_swaps[1],ctr2);
        	if(!flag3)
        		printf("Selection Sort: Expected: %ld, Your answer: %ld\n",expected_swaps[2],ctr3);
        }
        free(A);
        free(B);
        free(C);
    }
    fclose(data);
}
long int InsertionSort(Record* A, int n)
{
    int j;
    long int ctr = 0;
    for (int i=1;i<n;i++)
    {
        j = i-1;
        Record temp = A[i];
        while(j>=0 && A[j].serialnumber>temp.serialnumber)
        {
            ctr++;
            A[j+1] = A[j];
            j--;
        }
		if(j!=-1)
			ctr++;
        A[j+1] = temp;
    }
    return ctr;
}
long int BubbleSort(Record* A, int n)
{
    long int ctr = 0;
	int swap;
    for(int i=0;i<n-1;i++)
    {
        swap = 0;
        for(int j = 0;j<n-i-1;j++)
        {
            if (A[j].serialnumber>A[j+1].serialnumber)
            {
                Record temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
				swap = 1;
            }
            ctr++;
        }
		if(!swap)
			return ctr;
    }
    return ctr;
}
long int SelectionSort(Record* A, int n)
{
    int min;
    long int ctr = 0;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
            {
                if(A[j].serialnumber<A[min].serialnumber)
                    min = j;
                ctr++;
            }
            Record temp = A[i];
            A[i] = A[min];
            A[min] = temp;
    }
    return ctr;
}

int Sorted(Record *A, int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(A[i].serialnumber>A[i+1].serialnumber)
            return 0;
    }
    return 1;
}

double time_elapsed(struct timespec start, struct timespec end) {
	double t;
	t = (end.tv_sec - start.tv_sec);
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
	return t;
}

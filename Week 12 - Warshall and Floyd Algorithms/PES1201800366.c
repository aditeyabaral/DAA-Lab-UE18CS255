#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "session12_WarshallsFloyds.h"
int main()
{
   struct timespec start1, end1, start2, end2;
   char inputfiles[2][30] = {"session12_WarshallsFloyds_ip1.txt",
                        "session12_WarshallsFloyds_ip2.txt"};
                        
   char outfiles[2][30] = {"session12_WarshallsFloyds_op1.txt",
                        "session12_WarshallsFloyds_op2.txt"};
   int n1,n2;
   scanf("%d",&n1);
   int **g = (int**)malloc(sizeof(int*)*n1);
   for (int i = 0; i<n1; i++)
   {
      g[i] = (int*)malloc(sizeof(int)*n1);
      for (int j = 0; j<n1; j++)
         scanf("%d", &g[i][j]);
   }
   clock_gettime(CLOCK_REALTIME,&start1);
   transitive_closure_warshalls(g,n1);
   clock_gettime(CLOCK_REALTIME,&end1);
   printf("\n");
   scanf("%d", &n2);
   int **w = (int**)malloc(sizeof(int*)*n2);
   for (int i = 0; i<n1; i++)
   {
      w[i] = (int*)malloc(sizeof(int)*n2);
      for (int j = 0; j<n1; j++)
      {
         scanf("%d",&w[i][j]);
      }
   }
   clock_gettime(CLOCK_REALTIME,&start2);
   all_pairs_shortest_path_distances_floyds(w,n1);
   clock_gettime(CLOCK_REALTIME,&end2);
   printf("%lf sec spent\n",time_elapsed(start1,end1));
   printf("%lf sec spent\n",time_elapsed(start2,end2));
}

void transitive_closure_warshalls(int **g, int n)
{
    int dp[n+1][n][n];
    int i, j, k;
    for (k=0;k<=n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                dp[k][i][j] = g[i][j];
            }
        }
    }
    for (k=1;k<=n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                dp[k][i][j] = dp[k][i][j] || ((dp[k-1][i][k-1] && dp[k-1][k-1][j]) || dp[k-1][i][j]);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ",dp[n][i][j]);
        }
        printf("\n");
    }
}

void all_pairs_shortest_path_distances_floyds(int **g, int n)
{
    int dp[n+1][n][n];
    int i, j, k;
    for (k=0;k<=n;k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                dp[k][i][j] = g[i][j];
            }
        }
    }
    for (k=1; k<=n; k++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                dp[k][i][j] = max(min(min(dp[k-1][i][k-1] + dp[k-1][k-1][j], dp[k][i][j]), dp[k-1][i][j]), 0);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            printf("%d ", dp[n][i][j]);
        }
        printf("\n");
    }
}

double time_elapsed(struct timespec start, struct timespec end)
{
   double t;
   t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
   t += (end.tv_nsec - start.tv_nsec)*0.000000001;   //add diff of tv_nsec too
   return t;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if(a>b)
        return b;
    else
        return a;
}


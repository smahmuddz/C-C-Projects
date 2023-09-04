/*
1. Using C program, randomly generate a directed graph represented by adjacency matrix with
n = 1000 vertices.
2. Determine in-degrees and out-degrees of all vertices and show that sum of in-degrees and
sum of out-degrees are equal. Determine computational time in this step (except printing
time) in ms.
*/
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define max 9001
int adj_mat[max][max];
int main()
{
  int i, j, n, indeg = 0, outdeg = 0, in, out;

    double total_time;
    clock_t start,end;

    srand(2);
    printf("Enter the number of Vertices:\n");
    scanf("%d",&n);
    printf("\n");

    start=clock();

    for(i=0; i<n; i++)
        {
        for(j=0; j<n; j++)
        {
         {adj_mat[i][j] = rand()%2;}
        }
        }
   for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ",adj_mat[i][j]);
        }
        printf("\n");
    }
      printf("\n Vertex \t indegree \t out degree");
      //
    for(i=0; i<n; i++)
    {
        in= 0;
        out= 0;
        for(j=0; j<n; j++)
        {
            if(adj_mat[i][j]==1)
            {
                outdeg++;
                out++;
            }
            if(adj_mat[j][i]==1){
                indeg++;
                in++;
            }
            }

        printf("\n\n %5d \t\t %d \t\t %d\n\n",i+1,in,out);
    }

    end=clock();

    printf("\n  The total inDegree is : %d\n",indeg);
    printf("\n  The total out degree is : %d\n",outdeg);


    total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,3);
     printf("\n  Execution time is : %1f ms \n",total_time);
     printf("\n");
     return 0;
}

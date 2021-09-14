#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int adj_mat[9001][9001];
int main()
{
  int i, j, n,degree = 0,edge=0,sum=0;

    double total_time;
    clock_t start,end;

    printf("How many Vertices : ");
    scanf("%d",&n);
    srand(2);
    start=clock();

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        adj_mat[i][j]=rand()%2;
        if(adj_mat[i][j]==1&&i!=j)
        {
            adj_mat[j][i]=1;
        }
        else if(adj_mat[i][j]==0&&i!=j)
        {
            adj_mat[j][i]=0;
        }
        else if(i==j)
        {
            adj_mat[i][j]=0;
        }
    }
}
 for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf(" %d",adj_mat[i][j]);
        }
        printf("\n");
    }

     printf("\n Vertex \t Degree ");
    for ( i = 0 ; i < n ; i++ )
    {
        degree = 0;
        for ( j = 0 ; j < n ; j++ )
            if ( adj_mat[i][j] == 1)
                degree++;
        printf("\n\n %5d \t\t %d\n\n", i, degree);
    }

for(i=0;i<n;i++)
{
    degree=0;
    /*degreeB=0;*/
    for(j=0;j<n;j++)
    {
        if(adj_mat[i][j]==1)
        {
            degree++;
        }

        if(adj_mat[i][j]==1&&i>=j)
        {
            edge++;
        }

    }
    sum+=degree;
}

printf("\n\nTotal degreeres is: %d\n",sum);
printf("\n\nTotal edge is: %d\n",edge);
printf("\n\nThe Number of edge is=(Sum of Degree/2)=(%d/2)=%d" ,sum,sum/2);
printf("\n\nSo the handshaking theorem is proved\n\n");

    end=clock();
    total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,3);

     printf("\n  Execution time is : %1f ms \n",total_time);
     printf("\n");

     return 0;
}

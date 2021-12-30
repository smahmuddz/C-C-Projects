#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#define max 9001

int mat[max][max];

int main() {
int i, j, m, n;
int isReflexive=1,isSymmetric=1,isTransitive=1,isequivalence=1;
    printf("Enter the column dimension of the matrix: ");
    scanf("%d", &n);


    double total_time;
    clock_t start,end;
    start=clock();


    for(i = 0; i < n;i++) {
        for(j = 0; j < n;j++) {

                mat[i][j]=rand()%2;
        }
    }
    printf("The randomly generated matrix is : \n");
    for(i = 0; i < n;i++) {
        for(j = 0; j < n;j++) {

               printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
    //equivalence

    //Reflexive

    for(i = 0; i < n;i++) //o(n)
    if(mat[i][i]==0)
    {isReflexive=0;}

    //Symmetric

    for(i = 0; i < n;i++) {  //o(n^2)
        for(j = 0; j < n;j++){
            if(mat[i][j]!=mat[j][i])
            isSymmetric=0;
        }
    //Transitive

    for(i = 0; i < n;i++) {   // o(n^3)
        for(j = 0; j < n;j++){
          for( int k=0;k<n;k++){
               if(mat[i][j] && mat[j][k] && !mat[k][i])
               isTransitive=0;
          }
        }
    }

    if(!isReflexive || !isTransitive || !isSymmetric)
    isequivalence=0;

}
printf("\n");
if(isReflexive)
{printf("\nReflexive\n");}
if(!isReflexive)
{printf("Not Reflexive\n");}
if(isTransitive)
{printf("Transitive\n");}
if(!isTransitive)
{printf("Not Transitive\n");}
if(isSymmetric)
{printf("Symmetric\n");}
if(!isSymmetric)
{printf("Not Symmetric\n");}
if(isequivalence)
{printf("Equivalent");}
if(!isequivalence)
{printf("Not Equivalent");}

printf("\n");

end=clock();

total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,3);

     printf("\n  Execution time is : %1f ms \n",total_time);
     printf("\n");
return 0;
}

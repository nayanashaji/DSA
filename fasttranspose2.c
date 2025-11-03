#include <stdio.h>
#include <stdlib.h>
void fasttranspose(int a[4][3],int r,int c)
{
    int *total=(int*)calloc(c,sizeof(int));
    int i=1;
    for(int j=1;j<r;j++)
        total[a[j][1]]++;
    
    int *index=(int*)calloc(c+1,sizeof(int));
    index[0]=1;
    for(int i=1;i<c+1;i++)
    {
        index[i]=index[i-1]+total[i-1];
    }
    for(int i=0;i<c+1;i++)
    printf("%d",index[i]);
    int **at=(int**)malloc(sizeof(int*)*(r));
    for(int i=0;i<r;i++)
    at[i]=(int*)malloc(sizeof(int)*(c));
    at[0][0]=c;
    at[0][1]=r-1;
    at[0][2]=a[0][2];
    for( int i=1;i<r;i++)
    {
        int col=a[i][1];
        int pos=index[col]++;
        at[pos][0]=a[i][1];
        at[pos][1]=a[i][0];
        at[pos][2]=a[i][2];
    }
     for (int i = 0; i < r; i++)
        printf("%d\t%d\t%d\n", at[i][0], at[i][1], at[i][2]);
}

int main()
{
    int a[4][3]={{3,3,3},{0,0,1},{1,1,3},{2,1,2}};
    fasttranspose(a,4,3);
}
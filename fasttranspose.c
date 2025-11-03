#include <stdio.h>
#include <stdlib.h>
int main(){
    int r,c,n,i;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d",&c);
    printf("Enter number of non-zero elements: ");
    scanf("%d",&n);
    int **a=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++) a[i]=(int*)malloc(3*sizeof(int));
    a[0][0]=r;
    a[0][1]=c;
    a[0][2]=n;
    for(i=1;i<=n;i++){
        printf("Enter element %d (row col value): ",i);
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
    int *count=(int*)calloc(c,sizeof(int));
    for(i=1;i<=n;i++) count[a[i][1]]++;
    int *pos=(int*)malloc(c*sizeof(int));
    pos[0]=1;
    for(i=1;i<c;i++) pos[i]=pos[i-1]+count[i-1];
    int **b=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++) b[i]=(int*)malloc(3*sizeof(int));
    b[0][0]=c;
    b[0][1]=r;
    b[0][2]=n;
    for(i=1;i<=n;i++){
        int col=a[i][1];
        int p=pos[col]++;
        b[p][0]=a[i][1];
        b[p][1]=a[i][0];
        b[p][2]=a[i][2];
    }
    printf("Transpose in tuple form:\n");
    for(i=0;i<=n;i++) printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
    return 0;
}

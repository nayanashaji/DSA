#include <stdio.h>
#include <stdlib.h>

struct Term { int coeff, exp; };

void addPoly(struct Term A[], int m, struct Term B[], int n) {
    struct Term* result = (struct Term*)malloc((m+n)*sizeof(struct Term));
    int i=0,j=0,k=0;
    while(i<m && j<n) {
        if(A[i].exp==B[j].exp){
            result[k].coeff=A[i].coeff+B[j].coeff;
            result[k].exp=A[i].exp;
            i++; j++; k++;
        } 
        else if(A[i].exp>B[j].exp) 
        result[k++]=A[i++];
        else 
        result[k++]=B[j++];
    }
    while(i<m) result[k++]=A[i++];
    while(j<n) result[k++]=B[j++];
    printf("Resultant Polynomial: ");
    for(int x=0;x<k;x++) 
    printf("%dx^%d ",result[x].coeff,result[x].exp);
    free(result);
}

int main() {
    int m,n;
    printf("Enter no. of terms in poly1: "); 
    scanf("%d",&m);
    struct Term* A=(struct Term*)malloc(m*sizeof(struct Term));
    printf("Enter coeff and power (in descending order of power):\n");
    for(int i=0;i<m;i++) 
    scanf("%d %d",&A[i].coeff,&A[i].exp);

    printf("Enter no. of terms in second polynomial: "); 
    scanf("%d",&n);
    struct Term* B=(struct Term*)malloc(n*sizeof(struct Term));
    printf("Enter coeff and power (in descending order of power):\n");
    for(int i=0;i<n;i++) 
    scanf("%d%d",&B[i].coeff,&B[i].exp);

    addPoly(A,m,B,n);
    free(A); 
    free(B);
    return 0;
}

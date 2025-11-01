#include <stdio.h>
#include <stdlib.h>
int getMax(int arr[], int n){int max=arr[0];for(int i=1;i<n;i++) if(arr[i]>max) max=arr[i]; return max;}
void countSort(int arr[], int n, int exp){
    int *output=(int*)malloc(n*sizeof(int));
    int count[10]={0};
    for(int i=0;i<n;i++) count[(arr[i]/exp)%10]++;
    for(int i=1;i<10;i++) count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--) output[--count[(arr[i]/exp)%10]]=arr[i];
    for(int i=0;i<n;i++) arr[i]=output[i];
    free(output);
}
void radixSort(int arr[], int n){
    int m=getMax(arr,n);
    for(int exp=1;m/exp>0;exp*=10) countSort(arr,n,exp);
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    radixSort(arr,n);
    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    free(arr);
    return 0;
}

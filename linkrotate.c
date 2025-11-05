#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node *next;};
struct Node *head=NULL;
void insertEnd(int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x; newNode->next=NULL;
    if(head==NULL){head=newNode; return;}
    struct Node *temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
}
struct Node* rotate(struct Node* h,int k){
    if(h==NULL || h->next==NULL || k==0) return h;
    int len=0;
    struct Node *temp=h;
    while(temp!=NULL){len++; temp=temp->next;}
    k=k%len;
    if(k==0) return h;
    struct Node *current=h;
    for(int i=1;i<k;i++) current=current->next;
    struct Node *newHead=current->next;
    current->next=NULL;
    temp=newHead;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=h;
    return newHead;
}
void display(struct Node* h){
    struct Node *temp=h;
    while(temp!=NULL){printf("%d ",temp->data); temp=temp->next;}
    printf("\n");
}
int main(){
    int n,x,k;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(x);}
    printf("Enter k for rotation: ");
    scanf("%d",&k);
    printf("Original list: "); display(head);
    head=rotate(head,k);
    printf("Rotated list: "); display(head);
    return 0;
}

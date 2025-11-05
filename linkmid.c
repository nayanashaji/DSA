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
int findMiddle(){
    if(head==NULL){printf("List empty\n"); return -1;}
    struct Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
void display(){
    struct Node *temp=head;
    while(temp!=NULL){printf("%d ",temp->data); temp=temp->next;}
    printf("\n");
}
int main(){
    int n,x;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(x);}
    printf("Linked list: "); display();
    printf("Middle element: %d\n",findMiddle());
    return 0;
}

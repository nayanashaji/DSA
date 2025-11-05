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
struct Node* reverseList(struct Node* h){
    struct Node *prev=NULL,*current=h,*next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
void display(struct Node* h){
    struct Node *temp=h;
    while(temp!=NULL){printf("%d ",temp->data); temp=temp->next;}
    printf("\n");
}
int main(){
    int n,x;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(x);}
    printf("Original list: "); display(head);
    head=reverseList(head);
    printf("Reversed list: "); display(head);
    return 0;
}

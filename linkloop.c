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
int detectLoop(struct Node* h){
    struct Node *slow=h,*fast=h;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return 1;
    }
    return 0;
}
int main(){
    int n,x,loopPos;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(x);}
    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d",&loopPos);
    if(loopPos>0){
        struct Node *temp=head,*loopNode=NULL;
        for(int i=1;i<=n;i++){
            if(i==loopPos) loopNode=temp;
            if(temp->next!=NULL) temp=temp->next;
        }
        temp->next = loopNode;
    }
    if(detectLoop(head)) printf("Loop detected (1)\n");
    else printf("No loop (0)\n");
    return 0;
}

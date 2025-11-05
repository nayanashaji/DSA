#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node *next;};
struct Node* headA=NULL;
struct Node* headB=NULL;
void insertEnd(struct Node **head,int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x; newNode->next=NULL;
    if(*head==NULL){*head=newNode; return;}
    struct Node *temp=*head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
}
int getLength(struct Node *head){
    int len=0;
    while(head!=NULL){len++; head=head->next;}
    return len;
}
struct Node* getIntersectionNode(struct Node* headA,struct Node* headB){
    int lenA=getLength(headA),lenB=getLength(headB);
    int diff=(lenA>lenB)?lenA-lenB:lenB-lenA;
    struct Node *longer=(lenA>lenB)?headA:headB;
    struct Node *shorter=(lenA>lenB)?headB:headA;
    for(int i=0;i<diff;i++) longer=longer->next;
    while(longer!=NULL && shorter!=NULL){
        if(longer==shorter) return longer;
        longer=longer->next;
        shorter=shorter->next;
    }
    return NULL;
}
void display(struct Node *head){
    while(head!=NULL){printf("%d ",head->data); head=head->next;}
    printf("\n");
}
int main(){
    int nA,nB,x,interPos;
    printf("Enter number of nodes in List A: ");
    scanf("%d",&nA);
    for(int i=0;i<nA;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(&headA,x);}
    printf("Enter number of nodes in List B: ");
    scanf("%d",&nB);
    for(int i=0;i<nB;i++){printf("Enter element %d: ",i+1); scanf("%d",&x); insertEnd(&headB,x);}
    printf("Enter position in List A where List B should intersect (0 for no intersection): ");
    scanf("%d",&interPos);
    if(interPos>0){
        struct Node *tempA=headA;
        for(int i=1;i<interPos;i++) tempA=tempA->next;
        struct Node *tempB=headB;
        while(tempB->next!=NULL) tempB=tempB->next;
        tempB->next=tempA;
    }
    struct Node *interNode=getIntersectionNode(headA,headB);
    printf("List A: "); display(headA);
    printf("List B: "); display(headB);
    if(interNode!=NULL) printf("Intersection at node with value: %d\n",interNode->data);
    else printf("No intersection\n");
    return 0;
}

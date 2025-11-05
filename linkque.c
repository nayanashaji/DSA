#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node *next;};
struct Node *front=NULL, *rear=NULL;
void enqueue(int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(rear==NULL){front=rear=newNode; return;}
    rear->next=newNode;
    rear=newNode;
}
int dequeue(){
    if(front==NULL){printf("Queue empty\n"); return -1;}
    int val=front->data;
    struct Node *temp=front;
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
    return val;
}
int peek(){
    if(front==NULL){printf("Queue empty\n"); return -1;}
    return front->data;
}
void display(){
    if(front==NULL){printf("Queue empty\n"); return;}
    struct Node *temp=front;
    while(temp!=NULL){printf("%d ",temp->data); temp=temp->next;}
    printf("\n");
}
int main(){
    int ch,x;
    do{
        printf("1-Enqueue 2-Dequeue 3-Peek 4-Display 5-Exit: ");
        scanf("%d",&ch);
        if(ch==1){printf("Enter element to enqueue: "); scanf("%d",&x); enqueue(x);}
        else if(ch==2) printf("Dequeued: %d\n",dequeue());
        else if(ch==3) printf("Front element: %d\n",peek());
        else if(ch==4) display();
    }while(ch!=5);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int *dq, size, front=-1, rear=-1;
int isFull(){return (front==0 && rear==size-1)||((rear+1)%size==front);}
int isEmpty(){return front==-1;}
void insertFront(int x){
    if(isFull()) printf("Deque full\n");
    else{
        if(front==-1){front=rear=0;}
        else if(front==0) front=size-1;
        else front--;
        dq[front]=x;
    }
}
void insertRear(int x){
    if(isFull()) printf("Deque full\n");
    else{
        if(front==-1){front=rear=0;}
        else rear=(rear+1)%size;
        dq[rear]=x;
    }
}
int deleteFront(){
    if(isEmpty()){printf("Deque empty\n"); return -1;}
    int val=dq[front];
    if(front==rear) front=rear=-1;
    else front=(front+1)%size;
    return val;
}
int deleteRear(){
    if(isEmpty()){printf("Deque empty\n"); return -1;}
    int val=dq[rear];
    if(front==rear) front=rear=-1;
    else if(rear==0) rear=size-1;
    else rear--;
    return val;
}
void display(){
    if(isEmpty()){printf("Deque empty\n"); return;}
    int i=front;
    while(1){
        printf("%d ",dq[i]);
        if(i==rear) break;
        i=(i+1)%size;
    }
    printf("\n");
}
int main(){
    int ch,x;
    printf("Enter size of deque: ");
    scanf("%d",&size);
    dq=(int*)malloc(size*sizeof(int));
    do{
        printf("1-InsertFront 2-InsertRear 3-DeleteFront 4-DeleteRear 5-Display 6-Exit: ");
        scanf("%d",&ch);
        if(ch==1){printf("Enter element to insert at front: "); scanf("%d",&x); insertFront(x);}
        else if(ch==2){printf("Enter element to insert at rear: "); scanf("%d",&x); insertRear(x);}
        else if(ch==3) printf("Deleted from front: %d\n",deleteFront());
        else if(ch==4) printf("Deleted from rear: %d\n",deleteRear());
        else if(ch==5) display();
    }while(ch!=6);
    free(dq);
    return 0;
}

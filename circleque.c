#include <stdio.h>
#include <stdlib.h>
int *q, size, front=-1, rear=-1;
int isFull(){return (front==0 && rear==size-1)||((rear+1)%size==front);}
int isEmpty(){return front==-1;}
void enqueue(int x){
    if(isFull()) printf("Queue full\n");
    else{
        if(front==-1) front=0;
        rear=(rear+1)%size;
        q[rear]=x;
    }
}
int dequeue(){
    if(isEmpty()){printf("Queue empty\n"); return -1;}
    int val=q[front];
    if(front==rear) front=rear=-1;
    else front=(front+1)%size;
    return val;
}
void display(){
    if(isEmpty()){printf("Queue empty\n"); return;}
    int i=front;
    while(1){
        printf("%d ",q[i]);
        if(i==rear) break;
        i=(i+1)%size;
    }
    printf("\n");
}
int main(){
    int ch,x;
    printf("Enter size of circular queue: ");
    scanf("%d",&size);
    q=(int*)malloc(size*sizeof(int));
    do{
        printf("1-Enqueue 2-Dequeue 3-Display 4-Exit: ");
        scanf("%d",&ch);
        if(ch==1){printf("Enter element to enqueue: "); scanf("%d",&x); enqueue(x);}
        else if(ch==2) printf("Dequeued: %d\n",dequeue());
        else if(ch==3) display();
    }while(ch!=4);
    free(q);
    return 0;
}

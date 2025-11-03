#include <stdio.h>
#include <stdlib.h>
int *s1,*s2,top1=-1,top2=-1,size;
int isFull(){return top1==size-1;}
int isEmpty(){return top1==-1 && top2==-1;}
void push(int *s,int *top,int x){s[++(*top)]=x;}
int pop(int *s,int *top){return s[(*top)--];}
void enqueue(int x){if(isFull()) printf("Queue full\n"); else push(s1,&top1,x);}
int dequeue(){
    if(isEmpty()){printf("Queue empty\n"); return -1;}
    if(top2==-1) while(top1!=-1) push(s2,&top2,pop(s1,&top1));
    return pop(s2,&top2);
}
void display(){
    if(isEmpty()){printf("Queue empty\n"); return;}
    for(int i=top2;i>=0;i--) printf("%d ",s2[i]);
    for(int i=0;i<=top1;i++) printf("%d ",s1[i]);
    printf("\n");
}
int main(){
    int ch,x;
    printf("Enter size of queue: ");
    scanf("%d",&size);
    s1=(int*)malloc(size*sizeof(int));
    s2=(int*)malloc(size*sizeof(int));
    do{
        printf("1-Enqueue 2-Dequeue 3-Display 4-Exit: ");
        scanf("%d",&ch);
        if(ch==1){printf("Enter element to enqueue: "); scanf("%d",&x); enqueue(x);}
        else if(ch==2) printf("Dequeued: %d\n",dequeue());
        else if(ch==3) display();
    }while(ch!=4);
    free(s1); free(s2);
    return 0;
}

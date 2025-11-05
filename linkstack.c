#include <stdio.h>
#include <stdlib.h>
struct Node{int data; struct Node *next;};
struct Node *top=NULL;
void push(int x){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}
int pop(){
    if(top==NULL){printf("Stack empty\n"); return -1;}
    int val=top->data;
    struct Node *temp=top;
    top=top->next;
    free(temp);
    return val;
}
int peek(){
    if(top==NULL){printf("Stack empty\n"); return -1;}
    return top->data;
}
void display(){
    if(top==NULL){printf("Stack empty\n"); return;}
    struct Node *temp=top;
    while(temp!=NULL){printf("%d ",temp->data); temp=temp->next;}
    printf("\n");
}
int main(){
    int ch,x;
    do{
        printf("1-Push 2-Pop 3-Peek 4-Display 5-Exit: ");
        scanf("%d",&ch);
        if(ch==1){printf("Enter element to push: "); scanf("%d",&x); push(x);}
        else if(ch==2) printf("Popped: %d\n",pop());
        else if(ch==3) printf("Top element: %d\n",peek());
        else if(ch==4) display();
    }while(ch!=5);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
struct Node
{
int data;
struct Node *left,*right;
};
struct Node* newNode(int x){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->left=n->right=NULL;
    return n;
}
void inorderRec(struct Node* r)
{
if(r)
{
inorderRec(r->left);
printf("%d ",r->data);
inorderRec(r->right);
}
}
void preorderRec(struct Node* r)
{
if(r)
{
printf("%d ",r->data);
preorderRec(r->left);
preorderRec(r->right);
}
}
void postorderRec(struct Node* r)
{
if(r)
{
postorderRec(r->left);
postorderRec(r->right);
printf("%d ",r->data);
}
}
void inorderIt(struct Node* root)
{
    struct Node* stack[50];int top=-1;
    struct Node* curr=root;
    while(curr||top!=-1)
    {
        while(curr)
        {
        stack[++top]=curr;curr=curr->left;
        }
        curr=stack[top--];
        printf("%d ",curr->data);
        curr=curr->right;
    }
}
void preorderIt(struct Node* root)
{
    if(!root)
    return;
    struct Node* stack[50];
    int top=-1;
    stack[++top]=root;
    while(top!=-1)
    {
    struct Node* curr=stack[top--];
    printf("%d ",curr->data);
        if(curr->right)
        stack[++top]=curr->right;
        if(curr->left)
        stack[++top]=curr->left;
    }
}
void postorderIt(struct Node* root)
{
    if(!root)return;
    struct Node* s1[50],*s2[50];
    int t1=-1,t2=-1;
    s1[++t1]=root;
    while(t1!=-1)
    {
    struct Node* curr=s1[t1--];
        s2[++t2]=curr;
        if(curr->left)
        s1[++t1]=curr->left;
        if(curr->right)
        s1[++t1]=curr->right;
    }
    while(t2!=-1)printf("%d ",s2[t2--]->data);
}
int main(){
    struct Node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    printf("Recursive Inorder: ");
    inorderRec(root);
    printf("\nRecursive Preorder: ");
    preorderRec(root);
    printf("\nRecursive Postorder: ");
    postorderRec(root);
    printf("\nIterative Inorder: ");
    inorderIt(root);
    printf("\nIterative Preorder: ");
    preorderIt(root);
    printf("\nIterative Postorder: ");
    postorderIt(root);
    return 0;
}
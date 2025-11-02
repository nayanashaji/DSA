#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
int min;
void push(int x)
{
if(top==MAX-1)
{
printf("stack overflow");
return;
}
if(top==-1)
{
stack[++top]=x;
min=x;
}
else if(x>=min)
{
stack[++top]=x;
}
else
{
stack[++top]=2*x-min;
min=x;
}
}
int pop()
{
if(top==1)
{
printf("Stack unerlfow");
return -1;
}
int t=stack[top--];
if(t>=min)
{
return t;
}
else
{
int prevmin=min;
min=2*min-t;
return prevmin;
}
}
int getmin()
{
if(top==-1)
{
printf("stack is empty");
return -1;
}
return min;
}
int main()
{
int n,val;
printf("enter no. of elements:");
scanf("%d",&n);
printf("Enter elements:");
for(int i=0;i<n;i++)
{
scanf("%d",&val);
push(val);
}
printf("current min: %d\n",getmin());
printf("pop: %d\n",pop());
printf("currnet min: %d",getmin());
return 0;
}
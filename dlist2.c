#include<stdio.h>
#include<stdlib.h>
//stack
#define M 5
typedef struct stack
{
    int top;
    int arr[M];
}STK;

void init(STK *t)
{
    t->top==-1;
}
void push(STK *t,int d)
{
    if(t->top==M-1)
    printf("\noverflow");
    return;
    t->arr[++t->top]=d;
}
int isEmpty(STK *t)
{
    return t->top=-1;
}
void pop(STK *t)
{
    if(isEmpty(t))
    printf("\nunderflow");
    else
    t->top--;
}
void display(STK *t)
{  
   int i=t->top;
    if(isEmpty(t))
    printf("\nempty list");
    else
    {
        printf("\ndata\n");
        while(i>=0)
        {
            printf("%4d",t->arr[i]);
            i--;
        }
    }
}
void main()
{
    int opt,d;
    STK p;
    init(&p);
    while(1)
    {
        printf("\nstack menu\n1.push\n2.pop\n3.disply\n4.exit\noption");
        scanf("%d",&opt);
        if(opt>3)
        break;
        switch(opt)
        {
            case 1:
             printf("\nenter number");
             scanf("%d",&d);
             push(&p,d); break;
             case 2:
             pop(&p);break;
             case 3:
             display(&p);break;

        }

    }
}
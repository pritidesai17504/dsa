#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *next;
}NODE;
NODE *st=NULL;
//function to create A NODE
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(d*sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
//functoin to retrive last node address
NODE *getlastnode()
{
    NODE *a=st;
    while(a->next!=NULL)
    a=a->next;
    return a;
}
//function to add new node at end
void addE(int d)
{
 NODE *a,*b;
 if(st==NULL)
 st=createNode(d);
 else
 {
    a=createNode(d);
    b=getlastnode();
    b->next=a;
 }
}
//function to add new node at begin
void addB(int d)
{
  NODE *a=createNode(d);
  a->next=st;
  st=a;  
}
//function to display data
void display()
{
    NODE *a=st;
    if(st==NULL)
    printf("\nempty list");
    else
    {
        printf("\ndata\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }

    }
}
//function to count nodes from the list
int count()
{
    NODE *a=st;
    int cnt=0;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}
int sum()
{ 
  NODE *a=st;
  int tot=0;
  while(a!=NULL)
  {
    tot+=a->data;
    a=a->next;
  }
return tot;
}
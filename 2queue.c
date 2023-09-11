#include<stdio.h>
//linked list implementation of queue
typedef struct node
{
    int data;
    struct node *next;
}NODE;
typedef struct queue
{
    NODE *fr;
    NODE *rr;
}QUE;
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
void init(QUE *t)
{
    t->fr=t->rr=NULL;
}
void insert(QUE *t,int d)
{
  NODE *a=createNode(d),*b;
  if(t->fr==NULL)
  {
    t->fr=a;
  }
  else
  {
    b=t->rr;
    b->next=a;
  }
  t->rr=a;
}
void remque(QUE *t)
{
    NODE *a=t->fr;
    if(t->fr==NULL)
    printf("\nunderflow");
    else
    {
        if(t->fr==t->rr)
        t->rr=t->fr=NULL;
        else
        t->fr=a->next;
        free(a);
    }
}

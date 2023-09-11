#include<stdio.h>
#include<stdlib.h>
//linked list impletation using head node pointer
typedef struct node
{
int data;
struct node *next;
}NODE;
//function to create A NODE
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
NODE *getlastnode(NODE *a)
{
    while(a->next!=NULL)
    a=a->next;
    return a;
}
void addE(int d,NODE **p)
{
   NODE *a=createNode(d);
   NODE *b;
   if(*p==NULL)
   *p=a;
   else
   {
    b=getlastnode(*p);
    b->next=a;
   }
}
void addB(int d,NODE **p)
{
    NODE *a=createNode(d);
    a->next=*p;
    *p=a;
}
void display(NODE **p)
{
    NODE *a=*p;
    if(*p==NULL)
      printf("\nemoty list");
    else
    {
        printf("\nlist data\n");
        while(a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
    }
}
int count( NODE **p)
{
    NODE *a=*p;
    int cnt=0;
    while(a!=NULL)
    {
        cnt++;
        a=a->next;
    }
    return cnt;
}
int sum(NODE **p)
{
    NODE *a=*p;
    int tot=0;
    while(a!=NULL)
     {
        tot+=a->data;
        a=a->next;
     }
     return tot;
}
void main()
{
    int opt,d,res;
    NODE *st=NULL;
    while(1)
    {
        printf("\nmenu\n1.add end\n2.add begin\n3.display\n4.count\n5.sum\n6.exit\noptin:");
        scanf("%d",&opt);
        if(opt>5)
        break;
        switch(opt)
        {
            case 1:
              printf("\ndata at end");
              scanf("%d",&d);
              addE(d,&st);break;
              case 2:
              printf("\ndata at begin");
              scanf("%d",&d);
              addB(d,&st); break;
              case 3:
              display(&st); break;
              case 4:
              res=count(&st);
              printf("\nnode count:%d",res); break;
              case 5:
              res=sum(&st);
              printf("\ndata sum:%d",res);
        }
    }
}
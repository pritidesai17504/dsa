#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct singlelist
{
    NODE *st;
}SLIST;

void init(SLIST*t)
{
    t->st=NULL;
}

NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
NODE *getlastNode(NODE *a)
{
    while(a->next!=NULL)
    {
        a=a->next;
    }
    return a;
}
NODE * addE(SLIST *t,int d)
{
    NODE*a=t->st,*b;
    if(t->st==NULL)
    t->st=createNode(d);
     else
     {
         a=createNode(d);
         b=getlastNode(t->st);
         b->next=a;
     }
     return a;
}
int mid(SLIST*t,int n)
{ 
    NODE*a=t->st;
    int mid;
    int cnt=0;
    while(a!=NULL)
    {
        cnt++;
      if(cnt!=(n/2)+1 && a!=NULL)
       a=a->next;
      else
       mid=a->data;
    }
    return mid;
}

        

int main(void) {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        SLIST p;
        init(&p);
        int n,d;
        scanf("%d",&n);
        int i=0;
        while(i<n)
        {
            scanf("%d",&d);
            addE(&p,d);
            i++;
        }
        printf("%d",mid(&p,n));
        printf("\n");
    }
	// your code goes here
	return 0;
}


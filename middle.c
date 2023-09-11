#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;
  
     NODE *st=NULL;
  
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}
NODE *getlastNode()
{
    NODE*a=st;
    while(a->next!=NULL)
    {
        a=a->next;
    }
    return a;
}
NODE* addE(int d)
{
    NODE*a=st,*b;
    if(st==NULL)
     st=createNode(d);
     else{
         a=createNode(d);
         b=getlastNode();
         b->next=a;
     }
     return a;
}

int mid(int n)
{ 
    NODE*a=st;
    int mid=0;
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
        int n,d;
        scanf("%d",&n);
        int i=0;
        while(i<n)
        {
            scanf("%d",&d);
            addE(d);
            i++;
        }
        printf("%d",mid(n));

    
	// your code goes here
	return 0;
}


#include<stdio.h>


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

void main()
{
    int opt,d,res;
    while(1)
    {
        printf("\nmenu\n1.add at end\n2.add at begin\n3.display\n4.count\n5.exit\noption:");
        scanf("%d",&opt);
        if(opt>4)
        break;
        switch(opt)
        {
            case 3:
            display(); break;
            case 4:
            printf("data count:%d",count());
            case 1:
            printf("data at end:");
            scanf("%d",&d);
            addE(d); break;
            case 2:
            printf("\ndata at begin:");
            scanf("%d",&d);
            addB(d); break;
        }
    }

}
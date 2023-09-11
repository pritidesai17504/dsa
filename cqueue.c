//circular queue
#include<stdio.h>
#define M 5
typedef struct queue
{
    int arr[M];
    int fr,rr;
}CQ;
void init(CQ *t)
{
    int i=0;
   while(i<M)
   {
     t->arr[i]=-1;
     i++;
   }
   t->rr=t->fr=M-1;
}
int count(CQ *t)
{
    int i=0,cnt=0;
    while(i<M)
    {
        if(t->arr[i]==-1)
        cnt++;
        i++;
    }
    return cnt;
}
void insert(CQ *t,int d)
{
    if(count(t)==0)
    printf("\noverlow");
    else
    t->rr++;
    t->arr[t->rr]=d;
}
void remque(CQ *t,int d)
{
    if(count(t)==M)
    printf("\nunderflow");
    else
    {  
        if(t->fr==M-1)
        t->fr=0;
        else
         t->fr++;
         t->arr[t->fr]=-1;
    }
}
void display(CQ *t)
{
   int i;
   if(count(t)==M)
   printf("\nempty queue");
   else{
    printf("\ndata\n");
    if(t->fr<t->rr)
    {
        for(i=t->fr+1;i<=t->rr;i++)
            printf("%4d",t->arr[i]);
    }
    else
    {
        for(i=t->fr+1;i<M;i++)
        printf("%4d",t->arr[i]);
        for(i=0;i<=t->rr;i++)
        printf("%4d",t->arr[i]);
    }
   }
}
int menu()
{
    int opt;
        printf("\ncircular queue menu\n1insert\n2.remove\n3.display\nexit\noption:.");
        scanf("%d",&opt);
        return opt;
}
int main()
{
    int opt,d;
    CQ p;
    init(&p);
    while(1)
    {
        opt=menu();
        if(opt>3)
        break;
        switch(opt)
        { 
           
            case 1:
            printf("\ndata:");
            scanf("%d",&d);
            insert(&p,d);
            break;
            case 2:
            remque(&p,d);break;
            case 3:
            display(&p);
            break;
        }
    }
}
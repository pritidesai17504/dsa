#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coe;
    int man;
    struct node *next;
}NODE;
typedef struct poly
{
    NODE *st;
}POLY;
void init(POLY*t)
{
    t->st=NULL;
}
NODE *createNode(int c,int m)
{
    NODE *a=(NODE*)malloc(sizeof(NODE));
    a->coe=c;
    a->man=m;
    a->next=NULL;
    return a;
}
void delAll(POLY *t)
{
    NODE *a=t->st;
    while(t->st=NULL)
    {
        t->st=a->next;
        free(a);
        a=t->st;
    }
}
void createPoly(POLY *t)
{
    NODE *a=t->st,*b;
    int c,m;
    delAll(t);
    while(1)
    {
        printf("\ncoe man\n");
        scanf("%d %d",&c,&m);
        if(c==0 && m==0)
        break;
        if(m<0)
        {
            printf("\ninvalid mantisa");
            continue;
        }
        if(t->st==NULL)
        {
            a=createNode(c,m);
            t->st=a;
        }
        else
        {
            if(m>=b->man)
           {
            printf("\ninvalid");
            continue;
           }
         a=createNode(c,m);
         b->next=a;
        }
        b=a;
    }

}
void display(POLY *t)
{
    NODE *a=t->st;
    printf("\npoly list");
    while(a!=NULL)
    {
        if(a->coe>0)
        printf("+");
        printf("%dX%d",a->coe,a->man);
        a=a->next;
    }
}
POLY add(POLY *p,POLY *q)
{
    POLY t;
    int c1,m1;
    NODE *a=p->st,*b=q->st,*c,*d;
    init(&t);
        while(a&&b)
        {
            if(a->man==b->man)
            {
            c1=a->coe+b->coe;
            m1=a->man;
            a=a->next;
            b=b->next;
            }
            else
            {
                if(a->man>b->man)
               {
                c1=a->coe;
                m1=a->man;
                a=a->next;
              }
              else
              {
                c1=b->coe;
                m1=b->man;
                b=b->next;
              }
            }
           if(t.st==NULL)
           c=d=t.st=createNode(c1,m1);
           else{
            c=createNode(c1,m1);
            d->next=c;
            d=c;
           }
           while(a!=NULL)
           {
            c=createNode(a->coe,a->man);
            d->next=c;
            d=c;
            a=a->next;
           }
           while(b!=NULL)
           {
            c=createNode(b->coe,b->man);
            d->next=c;
            d=c;
            b=b->next;
           }
        }
    return t;
}
POLY sub(POLY *p,POLY *q)
{
    POLY t;
    int c1,m1;
    NODE *a=p->st,*b=q->st,*c,*d;
    init(&t);
        while(a&&b)
        {
            if(a->man==b->man)
            {
            c1=a->coe-b->coe;
            m1=a->man;
            a=a->next;
            b=b->next;
            }
            else
            {
                if(a->man>b->man)
               {
                c1=a->coe;
                m1=a->man;
                a=a->next;
              }
              else
              {
                c1= (-1)*b->coe;
                m1=b->man;
                b=b->next;
              }
            }
           if(t.st==NULL)
           c=d=t.st=createNode(c1,m1);
           else{
            c=createNode(c1,m1);
            d->next=c;
            d=c;
           }
           while(a!=NULL)
           {
            c=createNode(a->coe,a->man);
            d->next=c;
            d=c;
            a=a->next;
           }
           while(b!=NULL)
           {
            c=createNode((-1)*b->coe,b->man);
            d->next=c;
            d=c;
            b=b->next;
           }
           return t;
        }

}
POLY mul(POLY*p,POLY*q)
{
    POLY t;
    NODE *a=p->st,*b=q->st,*c,*d;
    int c1,m1;
    NODE *e;
    init(&t);
    while(b!=NULL)
    {
        a=p->st;
     {
      c1=a->coe*b->coe;
      m1=a->man+b->man;
      if(t.st==NULL)
      c=d=t.st=createNode(c1,m1);
      else
      {
        e=t.st;
        while(e!=NULL&&m1<=e->man)
        {
            if(e->man==m1)
            {
                e->coe=e->coe+c1;
                break;
            }
            e=e->next;
        }
        if(e!=NULL && m1>e->man)
        {
            c=createNode(c1,m1);
            c->next=e->next;
            e->next=c;
        }
        else
        {
            if(e==NULL)
            {
                c=createNode(c1,m1);
                d->next=c;
                d=c;
            }
        }
      } 
      a=a->next;
     }
     b=b->next;
    }
    return t;
}
void main()
{
    int opt;
    POLY a,b,c;
    init(&a);
    init(&b);
    init(&c);
    while(1)
    {
        printf("\nmenu\n1.createPoly 1\n2.createPoly 2 \n3.display poly 1\n4.display poly 2\n5.display poly 3\n6.addition\n7.substraction\n8.multiplication\n9.exit\noption:");
        scanf("%d",&opt);
        if(opt>8)
        break;
        switch(opt)
        {
            case 1:
             createPoly(&a); break;
             case 2:
             createPoly(&b); break;
             case 3:
             display(&a); break;
             case 4:
             display(&b); break;
             case 5:
             display(&c); break;
             case 6:
             c=add(&a,&b); break;
             case 7:
             c=sub(&a,&b); break;
             case 8:
             c=mul(&a,&b);break;
        }
    }
}
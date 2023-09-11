#include <stdio.h>
#include <stdlib.h>

// double linked list
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;

typedef struct doublelist
{
    NODE *st; // points to first node
    NODE *ed; // points to last node
} DLIST;

void init(DLIST *t)
{
    t->st = t->ed = NULL;
}

// create node
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->next = a->prev = NULL;
    a->data = d;
    return a;
}

// function to add new node at end
void addE(DLIST *t, int d)
{
    NODE *a = createNode(d);
    NODE *b = t->ed;
    if (t->st == NULL)
        t->st = a;
    else
    {
        b->next = a;
        a->prev = b;
    }
    t->ed = a;
}
// function to add new node at begin
void addB(DLIST *t, int d)
{
    NODE *a = createNode(d);
    NODE *b = t->st;
    if (t->ed == NULL)
        t->ed = a;
    else
    {
        b->prev = a;
        a->next = b;
    }
    t->st = a;
}
// function to display start to end
void displaySE(DLIST *t)
{
    NODE *a = t->st;
    if (t->st == NULL)
        printf("\nempty list");
    else
    {
        printf("\ndata\n");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}
// function to display end to satrt
void displayES(DLIST *t)
{
    NODE *a = t->ed;
    if (t->ed == NULL)
        printf("\nempty list");
    else
    {
        printf("\ndata\n");
        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->prev;
        }
    }
}
void delFirst(DLIST *t)
{
    NODE *a = t->st, *b;
    if (t->st == NULL) // list is empty
        return;
    if (t->st == t->ed) // if only one node
        t->st = t->ed = NULL;
    else
    {
        b = a->next;
        b->prev = NULL;
        t->st = b;
    }
    free(a);
}
// function to delete lst node from list

void delLast(DLIST *t)
{
    NODE *a = t->ed, *b;
    if (t->ed == NULL)
        return;
    if (t->ed == t->st) // only one node
        t->st = t->ed = NULL;
    else
    {
        b = a->prev;
        b->next = NULL;
        t->ed = b;
    }
    free(a);
}
// function to delete i th position node from the list
void deliNode(DLIST *t, int pos)
{
    NODE *a = t->st, *b, *c;
    int i = 1;
    if (t->st == NULL || pos < 1)
        return;
    if (pos == 1)
        delFirst(t);
    else
    {
        while (i < pos && a != NULL)
        {
            b = a;
            a = a->next;
            i++;
        }
        if (a == NULL)
            return;          // requsted node not exit
        if (a->next == NULL) // last node from the list
            delLast(t);      // delete last node from the list
        else
        {
            b = a->prev;
            c = a->next;
            b->next = c;
            c->prev = b;
            free(a);
        }
    }
}

//
void insertB(DLIST *t, int d, int pos)
{
    int i = 1;
    NODE *a = t->st, *b, *c;
    if (pos == 1)
        addB(t, d);
    else
    {
        while (i < pos && a != NULL)
        {
            b = a;
            a = a->next;
            i++;
        }
    }
    if (a == NULL)
    {
        printf("\nrequest node not valid");
        return;
    }
    else
    {
        c = createNode(d);
        b->next = c;
        c->prev = b;
        c->next = a;
        a->prev = c;
    }
}
// function to compute data sum
int sum(DLIST *t)
{
    int tot = 0;
    NODE *a = t->st;
    while (a != NULL)
    {
        tot = tot + a->data;
        a = a->next;
    }
    return tot;
}
// function to count nodes from dlist
int count(DLIST *t)
{
    int cnt = 0;
    NODE *a = t->st;
    while (a != NULL)
    {
        cnt++;
        a = a->next;
    }
    return cnt;
}
// function to insert new node after i th position
// void insertA(DLIST *t, int pos, int d)
// {
//     int i = 1;
//     NODE *a = t->st, *b, *c;
//     if (pos < 1)
//         return; // request is invalid
//     while (i < pos && a != NULL)
//     {
//         b = a;
//         a = a->next;
//         i++;
//     }
//     if (a == NULL)
//     {
//         printf("\nno such requst exist");
//         return;
//     }
//     if (a->next == NULL) // insertion after last node
//         addE(t, d);
//     else
//     {
//         b = a->next;
//         c = createNode(d);
//         a->next = c;
//         c->prev = a;
//         c->next = b;
//         b->prev = c;
//     }
// }
void insertA(DLIST*t,int pos,int d)
{
    int i=1,n=count(t);
    NODE *a=t->st,*b,*c;
    if(pos<1||pos>n)
    return;
    if(pos==n)
    addE(t,d);
    else{
        while(i<=pos)
        {
            b=a;
            a=a->next;
            i++;
        }
        c=createNode(d);
        b->next=c;
        c->prev=b;
        c->next=a;
        a->prev=c;
    }
}
void main()
{
    DLIST p;
    int opt, d, pos;
    init(&p);
    while (1)
    {
        printf("\nmenu\n1.addEnd\n2.addBigin\n3.displaySE\n4.displayES\n5.delete first\n6.delete last\n7.delete i th node\n8.insert before\n9.count\n10.sum\n11.insert after\n12.sexit\nopton:");
        scanf("%d", &opt);
        if (opt > 11)
            break;
        switch (opt)
        {
        case 1:
            printf("\nenter data value");
            scanf("%d", &d);
            addE(&p, d);
            break;
        case 2:
            printf("\nenter data value");
            scanf("%d", &d);
            addB(&p, d);
            break;
        case 3:
            displaySE(&p);
            break;
        case 4:
            displayES(&p);
            break;
        case 5:
            delFirst(&p);
            break;
        case 6:
            delLast(&p);
            break;
        case 7:
            printf("position to be deleted");
            scanf("%d", &pos);
            deliNode(&p, pos);
            break;
        case 8:
            printf("enter node position to insert before");
            scanf("%d", &pos);
            printf("\ndata value");
            scanf("%d", &d);
            insertB(&p, d, pos);
            break;
        case 9:
            printf("\nnode count:%d", count(&p));
            break;
        case 10:
            printf("\ndata sum:%d", sum(&p));
            break;
         case 11:
            printf("enter node position to insert after");
            scanf("%d", &pos);
            printf("\ndata value");
            scanf("%d", &d);
            insertA(&p,pos,d);
            break;
        }
    }
}
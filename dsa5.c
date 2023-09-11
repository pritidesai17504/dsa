#include<stdio.h>
#include<stdlib.h>
//create a header file with name slist.h  define data types NOSE  and SLIST,difine functions to manupleate 
typedef struct node
{
int data;
struct node *next;
}NODE;


typedef struct singlelist
{
    NODE *st;
    int cnt;
}SLIST;

void init(SLIST *t)
{
    t->st=NULL;
    t->cnt=0;
}
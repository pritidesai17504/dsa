#include<stdio.h>
#define M 10
int main()
{
    int x[10];
    int sv,f1,i,f2,first,index,mid;
    while(i<10)
    {
        printf("\nenter number");
        scanf("%d",&x[i]);
        if(i<0&&x[i]<x[i-1])
        printf("\ninvalid");
        else
        i++;
    }
     printf("\nenter search value");
        scanf("%d",&sv);  
        f1=1;
        f2=0;
        mid=2;
        while(f1<10)
        {
            f1=f1+f2;
            f2=f1-f2;
            mid++;
        } 
        f2=f1-f2;
        f1=f1-f2;
        while(mid>0)
        {
            index=first+f1;
            if(index>=M||sv<x[index])
            {
                mid--;
                f2=f1-f2;
                f1=f1-f2;
            }
            else
            {
               if(sv=x[index])
               break;
               else
               {
                  first=index;
                  mid-=2;
                  f1=f1-f2;
                  f2=f1-f2;
               }
            }
        }
        if(mid>0)
        printf("\nfound at %d position",index);
        else
        printf("\nnot found");
}
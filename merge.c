#include<stdio.h>
#define M 10

    void input(int *a)
    {
        int i=0;
        printf("\nenter data:");
        while(i<M)
        {
            scanf("%d",(a+i));
            i++;
        }
    }
    void display(int *a,int flg)
    {
        int i=0;
        if(flg==0)
        {
            printf("\nbefore sorting");
        }
        else
            printf("\nAfter sorting");
            while(i<M)
    {
        printf("%d\n",*(a+i));
        i++;
    }
    }
    void merge(int *a)
    {
        int tmp[M],size=1;
        int i,j,k,l1,u1,l2,u2;
        while(size<M)
        {
            l1=0;k=0;
            while(l1+size<M)
            {
            l2=l1+size;
            u1=l2-1;
            if(l2+size<M)
            u2=l2+size-1;
            else
            u2=M-1;
            for(i=l1,j=l2;i<=u1&&j<=u2;k++)
                {
                    if(a[i]<a[j])
                    tmp[k]=a[i++];
                    else
                    tmp[k]=a[j++];
                }
                for(;i<=u1;i++)
                {
                    tmp[k++]=a[i];
                }
                for(;j<=u2;j++)
                    tmp[k++]=a[j];
                l1=u2+1;
            }
            for(i=l1;i<M;i++)
            tmp[k++]=a[i];
            for(i=0;i<M;i++)
            a[i]=tmp[i];
            size*=2;
        }
    }

    int main()
    {
        int x[M];
        input(x);
        display(x,0);
        merge(x);
        display(x,1);
    }

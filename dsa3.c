#include"list.h"

void main()
{
    int opt,d,res;
    while(1)
    {
        printf("\nmenu\n1.add at end\n2.add at begin\n3.display\n4.count\n5.sum\n6.exit\noption:");
        scanf("%d",&opt);
        if(opt>5)
        break;
        switch(opt)
        {
            case 3:
            display(); break;
            case 4:
            printf("data count:%d",count());
            case5:
            printf("data sum:%d",sum());
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
#include<stdio.h>

typedef struct student
{
    int rno;
    int tno;
    char nm[15];
    int state;
}STU;

typedef struct trade
{
    int tno;
    char tnm[15];
    int state;
}TRD;
FILE *fs;
FILE *ft;
STU s;
TRD t;
//funtion to search trd record
int tsearch(int no)
{
    int pos=0;
    rewind(ft);
    while(1)
    {
        fread(&t,sizeof(TRD),1,ft);
        if(feof(ft))
        {
            pos=-1;
            break;
        }
        if(t.tno==no)
         break;
         pos=ftell(ft);

    }
    return pos;
}
//function to add new trd type record
void tadd()
{
    int no,pos;
    printf("\ntrade id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=tsearch(no);
    if(pos>=0)
    {
        printf("\nrecord exists");
        return;
    }
    t.tno=no;
    printf("\ntrade name");
    scanf("%s",t.tnm);
    t.state=1;
    fwrite(&t,sizeof(TRD),1,ft);
    printf("\nrecord added");
    return;
}
//funtion to modify existing trade record

void tmod()
{
    int no,pos;
    printf("\ntrade id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=tsearch(no);
    if(pos==-1 || t.state==0)
    {
        printf("\nrecord not exists");
        return;
    }
    t.tno=no;
    printf("\ntrade name");
    scanf("%s",t.tnm);
    t.state=1;
    fseek(ft,pos,SEEK_SET);        //shifts file pointer to the byte no pos from begin of the file
    fwrite(&t,sizeof(TRD),1,ft);
    printf("\nrecord modified");
    return;
}
//funtion to delete trd type record
void tdel()
{
    int no,pos;
    printf("\ntrade id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=tsearch(no);
    if(pos==-1 || t.state==0)
    {
        printf("\nrecord not exists");
        return;
    }
    t.state=0;
    fseek(ft,pos,SEEK_SET);
    fwrite(&t,sizeof(TRD),1,ft);
    printf("\nrecord deleted");
    return;
}

//funtion to display trade records
void tdisplay()
{
    rewind(ft);
    printf("\ntrade data\n");
    while(1)
    {
        fread(&t,sizeof(TRD),1,ft);
        if(feof(ft))
        break;
        printf("\n%5d %-15s %5d",t.tno,t.tnm,t.state);
    }
    return;
}
 // funtion call trade menu
 void tmenu()
 {
    int opt,no,pos;
    while(1)
    {
        printf("\ntrade menu\n1.add\n2.mod\n3.del\n4.display\n5.search\n6.back\noption:");
        scanf("%d",&opt);
        if(opt>5)
        break;
        switch(opt)
        {
            case 1:
            tadd();break;
            case 2:
            tmod();break;
            case 3:
            tdel();break;
            case 4:
            tdisplay();break;
            case 5:
            printf("\ntrade no");
            scanf("%d",&no);
            if(pos==-1)
            printf("\nnot found");
            else{
                printf("\nrecord found");
                printf("\n%5d %-15s %d",t.tno,t.tnm,t.state);
            }
        }
    }
 }

void main()
{
    int opt;
    ft=fopen("trd.dat","r+b");
    if(ft==NULL)   //file open opertion failed
    {
        ft=fopen("trd.dat","wb");
        fclose(ft);
        ft=fopen("trd.dat","r+b");
    }
    tmenu();
    fclose(ft);
}




















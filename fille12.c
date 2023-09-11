#include<stdio.h>
typedef struct student
{
    int rno;
    int tno;
    int cno; //city no
    char nm[15];
    int state;
}STU;

typedef struct trade
{
    int tno;
    char tnm[15];
    int state;
}TRD;
typedef struct city
{
    int cno;
    char cnm[15];
    int state;
}CTY;
FILE *fs;
FILE *ft;
FILE *fc;
STU s;
TRD t;
CTY c;
//funtion to search trd record
int csearch(int no)
{
    int pos=0;
    rewind(fc);
    while(1)
    {
        fread(&c,sizeof(CTY),1,fc);
        if(feof(fc))
        {
            pos=-1;
            break;
        }
        if(c.cno==no)
         break;
         pos=ftell(fc);

    }
    return pos;
}
//function to add new trd type record
void cadd()
{
    int no,pos;
    printf("\ncity id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=csearch(no);
    if(pos>=0)
    {
        printf("\nrecord exists");
        return;
    }
    c.cno=no;
    printf("\ncity name");
    scanf("%s",c.cnm);
    c.state=1;
    fwrite(&c,sizeof(CTY),1,fc);
    printf("\nrecord added");
    return;
}
//funtion to modify existing trade record

void cmod()
{
    int no,pos;
    printf("\ncity id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=csearch(no);
    if(pos==-1 || c.state==0)
    {
        printf("\nrecord not exists");
        return;
    }
    c.cno=no;
    printf("\ncity name");
    scanf("%s",c.cnm);
    c.state=1;
    fseek(fc,pos,SEEK_SET);        //shifts file pointer to the byte no pos from begin of the file
    fwrite(&c,sizeof(CTY),1,fc);
    printf("\nrecord modified");
    return;
}
//funtion to delete trd type record
void cdel()
{
    int no,pos;
    printf("\ncity id");
    scanf("%d",&no);
    if(no<=0)
    {
        printf("\ninvalid");
        return;
    }
    pos=csearch(no);
    if(pos==-1 || c.state==0)
    {
        printf("\nrecord not exists");
        return;
    }
    c.state=0;
    fseek(fc,pos,SEEK_SET);
    fwrite(&c,sizeof(CTY),1,fc);
    printf("\nrecord deleted");
    return;
}

//funtion to display trade records
void cdisplay()
{
    rewind(fc);
    printf("\ncity data\n");
    while(1)
    {
        fread(&c,sizeof(CTY),1,fc);
        if(feof(fc))
        break;
        printf("\n%5d %-15s %5d",c.cno,c.cnm,c.state);
    }
    return;
}
 // funtion call trade menu
 void cmenu()
 {
    int opt,no,pos;
    while(1)
    {
        printf("\ncity menu\n1.add\n2.mod\n3.del\n4.display\n5.search\n6.back\noption:");
        scanf("%d",&opt);
        if(opt>5)
        break;
        switch(opt)
        {
            case 1:
            cadd();break;
            case 2:
            cmod();break;
            case 3:
            cdel();break;
            case 4:
            cdisplay();break;
            case 5:
            printf("\ncity no");
            scanf("%d",&no);
            if(pos==-1)
            printf("\nnot found");
            else{
                printf("\nrecord found");
                printf("\n%5d %-15s %d",c.cno,c.cnm,c.state);
            }
        }
    }
 }

void main()
{
    int opt;
    fc=fopen("cty.dat","r+b");
    if(fc==NULL)   //file open opertion failed
    {
        fc=fopen("cty.dat","wb");
        fclose(fc);
        fc=fopen("cty.dat","r+b");
    }
    cmenu();
    fclose(fc);
}

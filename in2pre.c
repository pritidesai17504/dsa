#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct stack
{
    int top;
    char opr[50];
}s;
char istr[100];  //infix expression
char pstr[100];
void push(char ch)
{
    s.top++;
    s.opr[s.top]=ch;
}
void pop()
{
    s.top--;
}
int empty()
{
    return(s.top==-1);
}

int preced(char stktop,char opr)
{
    return stktop!='('&&opr==')';
}
void reverse()
{   int i=0,k=strlen(istr)-1;
char tmp;
     while(i<k)
   {
      tmp=istr[i];
      istr[i]=istr[k];
      istr[k]=tmp;
      i++;
      k--;
   }
}
void in2pre()  //infix to postfix
{  
    char tmp;
   int i=0,j=0,k=strlen(istr)-1;
   char ch;
   s.top=-1;
   reverse();
//     while(i<k)
//    {
//       tmp=istr[i];
//       istr[i]=istr[k];
//       istr[k]=tmp;
//       i++;
//       k--;
//    }
   i=0;
  while(istr[i]!='\0')
  {
    if(istr[i]==')')
    istr[i]='(';
    else if(istr[i]=='(')
    istr[i]=')';
    else
    ;
    i++;
  }
  i=0;
    while(istr[i]!='\0')
    {
        if(isalpha(istr[i]))
        pstr[j++]=istr[i];
        else
        {
           while(!empty()&&preced(s.opr[s.top],istr[i]))
           {
            ch=s.opr[s.top];
            pop();
            pstr[j++]=ch;
           }
           if(empty()||istr[i]!=')')
           push(istr[i]);
           else
           pop();
        }
        i++;
    }
    while(!empty())
    {
        pstr[j++]=s.opr[s.top];
        pop();
    }
    pstr[j]='\0';
    
    i=0;
    k=strlen(pstr)-1;
     while(i<k)
   {
      tmp=pstr[i];
      pstr[i]=pstr[k];
      pstr[k]=tmp;
      i++;
      k--;
   }
}

void main()
{
    printf("\nenter infix string");
    scanf("%s",istr);
    in2pre();
    printf("%s",istr);
    
    printf("prefix expression %s",pstr);
}
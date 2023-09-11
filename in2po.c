#include<stdio.h>
#include<ctype.h>

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
void in2po()  //infix to postfix
{
   int i=0,j=0;
   char ch;
   s.top=-1;
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
}

void main()
{
    printf("\nenetr infix string");
    scanf("%s",istr);
    in2po();
    printf("fix expression %s",pstr);
}
//Infix to postfix
#include <stdio.h>
#include <conio.h>
#define MAX 20
char infix[MAX],oprstk[MAX],postfix[MAX];
int top=-1,i=0,j=-1;
int isopd(char c)
{
     if(c>='a' && c<='z')
     {
          return 1;
     }
     else{
          return 0;
     }
}
int isopr(char c)
{
     if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
     {
          return 1;
     }
     else{
          return 0;
     }
}
int priority(char c)
{
     if(c=='^')
     return 3;

     if(c=='*'|| c=='/')
     return 2;

     else
     return 1;
}
int main()
{
     char ch;
     printf("enter infix epression\n");
     scanf("%s",infix);
     while(infix[i]!='\0')
     {
         ch =infix[i];
         if(ch=='(')
         {
          top++;
          oprstk[top]=ch;
         }
         if(isopd(ch))
         {
          j++;
          postfix[j]=ch;
         }
         if(ch==')')
         {
          while(oprstk[top]!='(')
          {
               j++;
               postfix[j]=oprstk[top];
               top--;
          }
          top--;
         }
         if(isopr(ch))
         {
           if(oprstk[top]=='(')
           {
               top++;
               oprstk[top]=ch;
           }
           else if(priority(oprstk[top])<priority(ch))
           {
               top++;
               oprstk[top]=ch;
           }
           else{
               j++;
               postfix[j]=oprstk[top];
               oprstk[top]=ch;
           }
         }
          i++;

     }
     for(i=0;i<=j;i++)
     {
          printf("%c",postfix[i]);
     }
     return 0;
}
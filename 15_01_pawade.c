//Program to implement stack using array
#include<stdio.h>
#include<conio.h>
#define SIZE 20
int stk[SIZE],top=-1;
void push(int val)
{
     if(top==SIZE-1)
     {
          printf("stack s full\n");
     }
     else{
          top++;
          stk[top]=val;
     }
}
void pop()
{
     if(top==-1)
     {
          printf("stack is empty\n");
     }
     else{
          printf("%d is popped \n",stk[top]);
          top--;
     }
}
void display()
{
     if(top==-1)
     {
          printf("stack is empty\n");
     }
     else{
          printf("the elements are as follows:\n" );
          for(int i=0;i<=top;i++)
          {
               printf("%d\n",stk[i]);
          }
     }
}
int main()
{
     int val,ch;
     do{
          printf(" enter choice \n 1. push \n 2. pop \n 3. display \n 4. exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1: printf("enter value\n");
                       scanf("%d",&val);
                       push(val);
                       break;
               case 2: pop();
                       break;
               case 3: display();
                       break;
          }
     }while(ch<4);
     return 0;
}
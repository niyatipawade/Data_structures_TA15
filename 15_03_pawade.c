//two stacks using single array (generalise to n no. of stacks)
#include<stdio.h>
#include<conio.h>
#define SIZE 10
int stk[SIZE],top1=-1,top2=SIZE;
void push1(int val)
{
     if(top1==top2)
     {
          printf("stack is full\n");
     }
     else
     {
          top1++;
          stk[top1]=val;
     }
}
void pop1()
{
     if(top1==-1)
     {
          printf("stack is empty\n");
     }
     else
     {
          printf("%d is popped from stack 1\n",stk[top1]);
          top1--;
     }
}
void display1()
{
     if(top1==-1)
     {
          printf("stack is empty\n");
     }
     else{
     for(int i=0;i<=top1;i++)
     {
          printf("%d\n",stk[i]);
     }
     }
}
void push2(int val)
{
     if(top1==top2-1)
     {
          printf("stack is full\n");
     }
     else{
          top2--;
          stk[top2]=val;
     }
}
void pop2()
{
     if(top2==SIZE)
     {
          printf("stack is empty\n");
     }
     else{
      printf("%d is popped from stack 2\n",stk[top2]);
          top2++;    
     }
}
void display2()
{
     if(top2==SIZE)
     {
          printf("stack is empty\n");
     }
     else{
          for(int i=SIZE-1;i>=top2;i--)
          {
               printf("%d\n",stk[i]);
          }
     }
}
int main()
{
     int val,ch;
     do{
          printf("enter choice\n 1. push1\n 2. pop1\n 3. display1\n 4. push2\n 5. pop2\n 6. display2\n 7. exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:
                    printf("enter value\n");
                    scanf("%d",&val);
                    push1(val);
                    break;
               case 2:
                    pop1();
                    break;
               case 3:
               printf("elements are as follows:\n");     
               display1();
                    break;
               case 4:
                    printf("enter value\n");
                    scanf("%d",&val);
                    push2(val);
                    break;
               case 5:
                    pop2();
                    break;
               case 6:
               printf("elements are as follows:\n");     
               display2();
                    break;
          }
     }while(ch<7);

     return 0;
}

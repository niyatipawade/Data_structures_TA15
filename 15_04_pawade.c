//Two Queues using single array
#include<stdio.h>
#include<conio.h>
#define SIZE 10
int que[SIZE],rear1=-1,front1=0,rear2=SIZE,front2=SIZE-1;
void enqueue1(int val)
{
     if(rear1==rear2-1)
     {
          printf("queue is full\n");
     }
     else{
          rear1++;
          que[rear1]=val;
     }
}
void dequeue1()
{
     if(rear1==front1)
     {
          printf("queue is empty\n");
     }
     else{
          printf("%d was deleted from queue1\n",que[front1]);
          front1++;
     }
}
void display1()
{
     if(rear1==front1)
     {
          printf("queue is empty\n");
     }
     else{
          for(int i=front1;i<=rear1;i++)
          {
               printf("%d\n",que[i]);
          }
     }
}
void enqueue2(int val)
{
     if(rear1==rear2-1)
     {
          printf("queue is full\n");
     }
     else{
          rear2--;
          que[rear2]=val;
     }
}
void dequeue2()
{
     if(rear2==front2)
     {
          printf("queue is empty\n");
     }
     else{
          printf("%d was deleted from queue2\n",que[front2]);
          front2--;
     }
}
void display2()
{
     if(rear2==front2)
     {
          printf("queue is empty\n");
     }
     else{
          for(int i=front2;i>=rear2;i--)
          {
               printf("%d\n",que[i]);
          }
     }
}
int main()
{
     int val,ch;
     do{
          printf("enter choice\n 1.enqueue1\n2.dequeue1\n3.display1\n4.enqueue2\n5.dequeue2\n6.display2\n7.exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:
               printf("enter value\n");
               scanf("%d",&val);
               enqueue1(val);
               break;

               case 2:
               dequeue1();
               break;

               case 3:
               printf("elements are as follows:\n");
               display1();
               break;

               case 4:
               printf("enter value\n");
               scanf("%d",&val);
               enqueue2(val);
               break;

               case 5:
               dequeue2();
               break;

               case 6:
               printf("elements are as follows:\n");
               display2();
               break;
          }
     }while(ch<7);
     return 0;
}
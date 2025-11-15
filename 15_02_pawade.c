//Queue using array
#include<stdio.h>
#include<conio.h>
#define SIZE 20
int que[SIZE],front=0,rear=-1;
void enqueue(int val)
{
     if(rear==SIZE-1)
     {
          printf("queue is full\n");
     }
     else{
          rear++;
          que[rear]=val;
     }
}
void dequeue()
{
     if(front>rear)
     {
          printf("queue is empty\n");
     }
     else{
          printf("%d is deleted\n",que[front]);
          front++;
     }
}
void display()
{
     if(front>rear)
     {
          printf("queue is empty\n");
     }
     else{
          printf("the elements are as follows:\n" );
          for(int i=front;i<=rear;i++)
          {
               printf("%d\n",que[i]);
          }
     }
}
int main()
{
     int val,ch;
     do{
          printf(" enter choice \n 1. enqueue \n 2. dequeue \n 3. display \n 4. exit\n");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1: printf("enter value\n");
                       scanf("%d",&val);
                       enqueue(val);
                       break;
               case 2: dequeue();
                       break;
               case 3: display();
                       break;
          }
     }while(ch<4);
     return 0;
}
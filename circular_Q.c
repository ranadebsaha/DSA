//*** Array representation of circular queue ***//
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 3
int front,rear;
int queue[MAX];
int isEmpty(int*);
int isFull(int *);
void insert(int *,int);
int del(int *);
void display(int *);

int main()
{
    int x;
    int choice;
    
front=-1;
rear=-1;
do{
	printf("1. for Insert\n");
	printf("2. for Delete\n");
	printf("3. for Display\n");
	printf("4. for Quit\n");
	printf("Enter your choice:\n");
	//fflush(stdin);
	//op=getchar();
	scanf("%d",&choice);
	switch(choice){
	case 1:
	{
         if(isFull(queue))
         {
            printf("Queue is full\n");
            break;
         }
	printf("\n Enter the element to be inserted\n");
	scanf("%d",&x);
	insert(queue,x);
	break;
	}
	case 2:
	{
         if(isEmpty(queue))
         {
           printf("Queue is empty\n");
           break;
         }
         x=del(queue);
	printf("\n Deleted element is %d",x);
	break;
	}
	case 3:
	{ 
         if(isEmpty(queue))
         {
           printf("Queue is empty\n");
           break;
         }
         display(queue);
	break;
	}
	case 4:
	break;
	default:
	printf("\nWrong choice ! Try again");
	}
	printf("\n Press any key to continue\n");
	getch();
	system("cls");
	//scanf("c",&k);
	//fflush(stdin);
	//k=getchar();
	}while(choice!=4);
	return 0;
	}
	int isEmpty(int queue[])
	{
        if(front==-1)
        return 1;
        else
        return 0;
	}
	int isFull(int queue[])
	{
        if(front==(rear+1)%MAX)
        return 1;
        else
        return 0;
	}
	/* Insert an item to the circular queue*/
	void insert(int queue[],int x)
	{
         if(front==-1)
         {
           front=0;
           rear=0;
         }
         else
         {
             rear=(rear+1)%MAX;
         }
             queue[rear]=x;
         
     }
	int del(int queue[])
	{
        int x;
        x=queue[front];
        if(front==rear)
        {
          front=-1;
          rear=-1;
        }
        else
        front=(front+1)%MAX;
        return x;
     }
 void display(int queue[])
 {
      int i;
      printf("Elements in the queue are...\n");
      if(front<=rear)
      {
        for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
      }
      else 
      {
        for(i=0;i<=rear;i++)
        printf("%d\t",queue[i]);
        for(i=front;i<=MAX-1;i++)
        printf("%d\t",queue[i]);
        
      }
 }

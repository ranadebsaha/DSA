//Queue using Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue* link;
}queue;

void insert(queue**,queue**);
void delete(queue**);
void display(queue*);

void main()
{
    queue* front= NULL;
    queue* rear=NULL;
    int ch;
    do{
        printf("\n\n---------Queue Operation---------\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: insert(&front,&rear);
                break;
            case 2: delete(&front);
                break;
            case 3: display(front);
                break;
            case 4: printf("Thank You for using RDS Code");
                break;
            default: printf("Invalid Choice"); 
                break;;       
        }
    }while(ch!=4);
}

void insert(queue** front, queue** rear){
    queue* temp;
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    temp=(queue*)malloc(sizeof(queue));
    temp->data=num;
    temp->link=NULL;
    if(*front==NULL){
        *front=temp;
        *rear=temp;
        return;
    }
    queue* ptr=*rear;
    ptr->link=temp;
    *rear=temp;
}

void delete(queue** front){
    queue* temp;
    if(*front==NULL){
        printf("Queue is Empty");
        return;
    }
    temp=*front;
    *front=(*front)->link;
    free(temp);
}

void display(queue* front){
    queue* temp=front;
    if(front==NULL){
        printf("Queue is Empty");
        return;
    }
    printf("Queue is: ");
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->link;
    }
}
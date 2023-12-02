//Queue using Array
#include <stdio.h>
#define MAX 5
void insert();
void delete();
void display();
int arr[5], front=-1,rear=-1;
void main(){   
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
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3: display();
                break;
            case 4: printf("Thank You for using RDS Code");
                break;
            default: printf("Invalid Choice"); 
                break;;       
        }
    }while(ch!=4);
}

void insert(){
    int num;
    if(rear==MAX-1){
        printf("Queue is Full");
        return;
    }
    else{
        printf("Enter a number: ");
        scanf("%d",&num);
        if(front==-1){
            front++;
        }
        rear++;
        arr[rear]=num;
        return;
    }
}

void delete(){
    if(front==-1){
        printf("Queue is Empty");
        return;
    }
    else{
        if(front==rear){
            front=rear=-1;
        }else{
        front++;
        }
        return;
    }
}

void display(){
    if(front==-1){
        printf("queue is Empty");
        return;
    }
    else{
       printf("Queue is: ");
    for(int i=front;i<rear+1;i++){
        printf("%d ",arr[i]);
    }
    return;
    }
    
}
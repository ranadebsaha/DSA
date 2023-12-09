#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int data;
    struct stack* link;
}stack;

void push(stack**);
void pop(stack**);
void display(stack*);

void main(){
    stack* top=NULL;
    int ch;
    do{
        printf("\n\n---------Stack Operation---------\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: push(&top);
                break;
            case 2: pop(&top);
                break;
            case 3: display(top);
                break;
            case 4: printf("Thank You for using RDS Code");
                break;
            default: printf("Invalid Choice"); 
                brea;   
        }
    }while(ch!=4);
}

void push(stack** top){
    stack* temp;
    int n;
    printf("Enter a value: ");
    scanf("%d",&n);
    temp=(stack*)malloc(sizeof(stack));
    temp->data=n;
    temp->link=*top;
    *top=temp;
    printf("%d is Successfully Pushed",n);
}

void pop(stack** top){
    if(*top==NULL){
        printf("Stack is Empty");
    }
    else{
        int val=(*top)->data;
        stack* temp=*top;
        *top=(*top)->link;
        printf("The Poped item is: %d",val);
        free(temp);
    }
}

void display(stack* top){
    stack* temp=top;
    
    if(top==NULL){
        printf("Stack is Empty");
    }
    else{
        printf("Stack is: ");
        while(temp!=NULL){
                printf("%d  ",temp->data);
                temp=temp->link;
        }
    }
}
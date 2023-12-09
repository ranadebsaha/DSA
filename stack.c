#include <stdio.h>
void push();
void pop();
void display();
int arr[5], top=0;
void main(){   
    int ch;
    do{
        printf("\n\n---------Stack Operation---------\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: printf("Thank You for using RDS Code");
                break;
            default: printf("Invalid Choice"); 
                break;       
        }
    }while(ch!=4);
}

void push(){
    int num;
    if(top==5){
        printf("Stack is Full");
        return;
    }
    else{
        printf("Enter a number: ");
        scanf("%d",&num);
        arr[top]=num;
        top++;
        return;
    }
}

void pop(){
    if(top==0){
        printf("Stack is Empty");
        return;
    }
    else{
        top--;
        return;
    }
}

void display(){
    if(top==0){
        printf("Stack is Empty");
        return;
    }
    else{
       printf("Stack is: ");
    for(int i=0;i<top;i++){
        printf("%d ",arr[i]);
    }
    return;
    }
    
}
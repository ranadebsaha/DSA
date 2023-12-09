#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} list;

list *create();
void insert_end(list *);
list *insert_beg(list *);
void insert_inter(list *);
void delete_end(list *);
list *delete_beg(list *);
list *delete_spec(list *);
void display(list *);

void main()
{
    struct node *start;
    start = NULL;
    int ch, num;
    do
    {
        printf("\n\n---------Linked List Operation---------\n\n");
        printf("1. Creation\n");
        printf("2. Insert from end\n");
        printf("3. Insert from Beginning\n");
        printf("4. Insert an intermediate Location\n");
        printf("5. Delete from end\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete an specific node\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = create();
            break;
        case 2:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                insert_end(start);
            }
            break;
        case 3:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                start = insert_beg(start);
            }

            break;
        case 4:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                insert_inter(start);
            }
            break;
        case 5:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                delete_end(start);
            }
            break;
        case 6:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                start = delete_beg(start);
            }
            break;
        case 7:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                start = delete_spec(start);
            }
            break;
        case 8:
            if (start == NULL)
            {
                printf("Please Create a node First..");
            }
            else
            {
                display(start);
            }
            break;
        case 9:
            printf("Thank You for using RDS Code");
            break;
        default:
            printf("Invalid Choice");
            break;
            ;
        }
    } while (ch != 9);
}

list *create()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    list *temp = (list *)malloc(sizeof(list));
    temp->data = num;
    temp->link = NULL;
    return temp;
}

void insert_end(list *start)
{
    int num;
    list *ptr;
    ptr = start;
    printf("Enter a number: ");
    scanf("%d", &num);
    list *temp = (list *)malloc(sizeof(list));
    temp->data = num;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
list *insert_beg(list *start)
{
    list *ptr;
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    list *temp = (list *)malloc(sizeof(list));
    temp->data = num;
    temp->link = start;
    return temp;
}
void insert_inter(list *start)
{
    int num, loc;
    list *ptr;
    ptr = start;
    printf("Enter a number: ");
    scanf("%d", &num);
    list *temp = (list *)malloc(sizeof(list));
    temp->data = num;
    temp->link = NULL;
    printf("Enter the location: ");
    scanf("%d", &loc);
    for (int i = 1; i < loc - 1; i++)
    {
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    ptr->link = temp;
}
void delete_end(list *start)
{
    list *ptr, *temp;
    ptr = start->link;
    temp = start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        temp = temp->link;
    }
    printf("%d is Deleted", ptr->data);
    temp->link = NULL;
    free(ptr);
}
list *delete_beg(list *start)
{
    list *ptr, *temp;
    ptr = start;
    temp = start->link;
    printf("%d is Deleted", ptr->data);
    free(ptr);
    return temp;
}

list *delete_spec(list *start)
{
    int num, val = 1, sig = 0;
    list *ptr, *temp, *root;
    ptr = start;
    root = start;
    printf("Enter the number: ");
    scanf("%d", &num);
    while (ptr->link != NULL)
    {
        if (ptr->data == num)
        {
            sig = 1;
            break;
        }
        ptr = ptr->link;
        val++;
    }
    if (sig == 0)
    {
        printf("%d is not present in this list.", num);
    }
    else if (sig == 1 && val == 1)
    {
        ptr = start;
        temp = start->link;
        printf("%d is Deleted", ptr->data);
        free(ptr);
        return temp;
    }
    else
    {
        ptr = start->link;
        temp = start;
        for (int i = 1; i < val - 1; i++)
        {
            ptr = ptr->link;
            temp = temp->link;
        }
        printf("%d is Deleted", ptr->data);
        temp->link = ptr->link;
        free(ptr);
    }
    return root;
}

void display(list *start)
{
    if (start == NULL)
    {
        printf("Empty ");
    }
    else
    {
        list *temp = start;
        printf("The list are: ");
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->link;
        }
    }
}
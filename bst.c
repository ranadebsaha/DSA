#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} bstnode;

int search(bstnode *, int);
bstnode *create();
void insert(bstnode *, bstnode *);
void inorder(bstnode *);
void preorder(bstnode *);
void postorder(bstnode *);

void main()
{
    bstnode *root = NULL;
    int ch, num;
    do
    {
        printf("\n\n---------Binary Search Tree Operation---------\n\n");
        printf("1. Creation\n");
        printf("2. Insert\n");
        printf("3. Search\n");
        printf("4. Delete(Not complete. Still Working on it..)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            root = create();
            break;
        case 2:
            if (root == NULL)
            {
                printf("Please create a tree First.");
            }
            else
            {
                printf("Enter Element: ");
                scanf("%d", &num);
                bstnode *newnode = (bstnode *)malloc(sizeof(bstnode));
                newnode->data = num;
                newnode->left = newnode->right = NULL;
                insert(root, newnode);
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("Please create a tree First.");
            }
            else
            {
                printf("Enter Search Element: ");
                scanf("%d", &num);
                if (search(root, num) == 0)
                {
                    printf("%d is not present in tree", num);
                }
                if (search(root, num) == 1)
                {
                    printf("%d is present in your Binary tree", num);
                }
            }
            break;
        case 4:
            // delete();
            printf("Not complete. Still Working on it.. Please continue with other operation");
            break;
        case 5:
            if (root == NULL)
            {
                printf("Please create a tree First.");
            }
            else
            {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\nPreorder Traversal: ");
                preorder(root);
                printf("\nPostorder Traversal: ");
                postorder(root);
            }

            break;
        case 6:
            printf("Thank You for using RDS Code");
            break;
        default:
            printf("Invalid Choice");
            break;
            ;
        }
    } while (ch != 6);
}

bstnode *create()
{
    int num;
    printf("Enter a number for Root: ");
    scanf("%d", &num);
    bstnode *root = (bstnode *)malloc(sizeof(bstnode));
    root->data = num;
    root->left = root->right = NULL;
    return root;
}
void insert(bstnode *root, bstnode *newnode)
{
    if (root->data > newnode->data)
    {
        if (root->left == NULL)
        {
            root->left = newnode;
        }
        else
        {
            insert(root->left, newnode);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = newnode;
        }
        else
        {
            insert(root->right, newnode);
        }
    }
}
int search(bstnode *root, int num)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == num)
    {
        return 1;
    }
    if (num < root->data)
    {
        return search(root->left, num);
    }
    else
    {
        return search(root->right, num);
    }
}
void inorder(bstnode *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
void preorder(bstnode *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(bstnode *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}
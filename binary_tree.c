#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    char data;
    struct node* left;
    struct node* right;
}bnode;

void inorder(bnode*);
void preorder(bnode*);
void postorder(bnode*);

void main()
{
    bnode* t;
    bnode *p,*q;
    t=NULL;
    p=(bnode*)malloc(sizeof(bnode));
    p->data='A';
    p->left=NULL;
    p->right=NULL;
    t=p;
    q=t;
    p=(bnode*)malloc(sizeof(bnode));
    p->data='B';
    p->left=p->right=NULL;
    q->left=p;
    q=p;
    p=(bnode*)malloc(sizeof(bnode));
    p->data='D';
    p->right=p->left=NULL;
    q->left=p;
    q=p;
    p=(bnode*)malloc(sizeof(bnode));
    p->data='G';
    p->left=p->right=NULL;
    q->right=p;
    q=t;
    p=(bnode*)malloc(sizeof(bnode));
    p->data='C';
    p->left=p->right=NULL;
    q->right=p;
    printf("Inorder Traversal: ");
    inorder(t);
    printf("\nPreorder Traversal: ");
    preorder(t);
    printf("\nPostorder Traversal: ");
    postorder(t);

}

void inorder(bnode* t){
    if(t!=NULL){
        inorder(t->left);
        printf("%c ",t->data);
        inorder(t->right);
    }
}
void preorder(bnode* t){
    if(t!=NULL){
        printf("%c ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(bnode* t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%c ",t->data);
    }
}
/* Binary search tree append function , push function  , pop function  and preorder function code */

#include <stdio.h>
#include<stdlib.h>
struct bst{
    struct bst *left;
    int data;
    struct bst *right;
    
};
struct stack
{
    struct bst *arr[10];
    int tos;
    
};
void push(struct stack *,struct bst *);
struct bst * pop(struct stack *);
void preorder(struct bst*);
void append(struct bst **, int);

int main()
{
    struct bst *root=NULL;
    for(int i=0; i<9; i++)
    {
        printf("\n Enter tree elements ");
        int C;
        scanf("%d",&C);
        append(&root,C);
    }
    
    printf("Preorder Traversal give the root element first (ROOT, LEFT,Right)\n");
    printf("Preorder Traversal of BST ");
    preorder(root);
    

    return 0;
}
void append(struct bst **pr,int x)
{
    struct bst *temp,*p,*prev;
    p=(struct bst *)malloc(sizeof(struct bst));
    if(p==NULL)
    {
        printf("Insufficient memory ");
        return ;
    }
    p->data=x;
    p->right=p->left=NULL;
    
    if(*pr==NULL)
    {
        *pr=p;
        return;
        
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
       if(temp->data>x)
       {
           temp=temp->left;
       }
       else{
           temp=temp->right;
       }
    }
    if(prev->data>x)
    {
        prev->left=p;
    }
    else{
        prev->right=p;
    }
}
void push(struct stack *p,struct bst *q)
{
    if(p->tos==9)
    {
        printf("Stack overflow ");
        return;
    }
    p->tos=p->tos+1;
    p->arr[p->tos]=q;
}
struct bst * pop(struct stack *p)
{
    struct bst *temp;
    if(p->tos==-1)
    {
        printf("Stack underflow");
        return NULL;
    }
    temp=p->arr[p->tos];
    p->tos=p->tos-1;
    return temp;
}
void preorder(struct bst *p)
{
    struct stack S;
    S.tos=-1;
   if(p==NULL)
   {
       printf("tree is empty ");
       return;
   }
   push(&S,p);
   while(S.tos!=-1)
   {
       p=pop(&S);
       while(p!=NULL)
       {
          printf("%d ",p->data);
          if(p->right!=NULL)
          {
              push(&S,p->right);
          }
          p=p->left;
       }
   }
   
}

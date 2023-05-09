/*
1.Create the expression tree if the algebric expression is given in infix form. 
For e.g. ((a+b)*(c+d))/ (e-(f+g)). (5 Marks)
2. For the above tree, write the  recursive functions to provide (3 x 5=15 Marks)
(a) Preorder  traversal sequence 
(b) Postorder traversal sequence
(c) Inorder traversal sequence with parenthesis
(d) Level order sequence
(f) spiral order sequence
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    char c;
    struct node *right;
};

typedef struct node tree;

struct lifo
{
    tree *ptr;
    struct lifo *next;
};
typedef struct lifo stack;

void push(stack **top, tree *ptr)
{
    stack *s;
    s= (stack *)malloc(sizeof(stack));
    
    s->ptr = ptr;
    s->next = *top;
    *top = s;
}

tree * pop(stack **top)
{
    tree *p;
    stack *temp;
    temp = *top;
    
    if(temp==NULL)
        printf("Stack is Empty");
    else
    {
        
        temp = *top;
        p = temp->ptr;
        *top = temp->next;
        free(temp);
    }
        
    return p;
}
/*int preced(char sym)
{
    int x = 0;
    if(sym == '^')
        x=2;
    else if(sym == '*' || sym == '/')
        x=1;
        
    return x;
}
*/

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %c",root->c);
        inorder(root->right);
    }
}

void preorder(tree *root)
{
    if(root != NULL)
    {
        printf(" %c",root->c);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(tree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %c",root->c);
    }
}

int heighttree(struct node*next)
{
    int h;
    if(root==NULL)
    return 0;
    
    int left=heighttree(root->left);
    int right=heighttree(root->right);
    
    if(left>=right)
    h=left+1;
    else if(right<left)
    h=right+1;
    
    return h;
}

void levelorder(struct node*root,int height)
{
    int level=height;
    if(root==NULL)
    return;
    
}

int main()
{
    char infix[100];
    tree *p,*temp;
    int i;
    stack *sy=NULL,*op=NULL;
    
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    
    for(i=0;infix[i]!='\0';i++)
    {
        p=(tree *)malloc(sizeof(tree));
        p->left = NULL;
        p->right = NULL;
        if(infix[i]=='(')
        {
            p->c = '(';
            push(&sy,p);
        }
        else if(infix[i]==')')
        {
            // while(sy->ptr->sym!='(' && sy!=NULL)
            // {
                temp = pop(&sy);
                temp->right = pop(&op);
                temp->left = pop(&op);
                push(&op,temp);
            // }
            pop(&sy);
        }
        else if(sy!=NULL && (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-'))
        {
            // while(preced(sy->ptr->sym) >= preced(infix[i]) || sy->ptr->sym != '(')
            // {
            //     temp=pop(&sy);
            //     temp->right=pop(&op);
            //     temp->left=pop(&op);
            //     push(&op,temp);
            // }
            p->c = infix[i];
            push(&sy,p);
        }
        else
        {
            p->c = infix[i];
            push(&op,p);
        }
    }
    
    while(sy != NULL)
    {
        temp = pop(&sy);
        if(temp->c != '(')
        {
            temp->right = pop(&op);
            temp->left = pop(&op);
            push(&op,temp);
        }
    }
    
    tree *root;
    root = pop(&op);
    
    printf("\nInfix is : ");
    inorder(root);
    printf("\nPrefix is : ");
    preorder(root);
    printf("\nPostfix is : ");
    postorder(root);
    
    return 0;
}
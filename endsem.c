// BST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node*left;
    struct node*right;
};

struct node* newnode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));

    newnode->key=data;
    temp->left=temp->right=NULL;
    return newnode;
}

struct node* search(struct node*root,int data)
{
    if(data=root->key)
    {
        return root;
    }
    else if(data>root->left)
    {
        return search(root->right,data);
    }
    else
    {
        return search(root->left,data);
    }
}

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d",root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node,int key);
{
    if(node==NULL)
    {
        return newnode(key);
    }
    if(key>node->key)
    {
        node->right=insert(node->right,key);
    }
    else(key<node->key)
    {
        node->left=insert(node->left,key);
    }
    return node;
}

struct node *min(struct node*node)
{
    struct node*temp=node;
    while(temp && temp->left !=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

struct node*delete(struct node*root,int key)
{
    if(root==NULL)
    {
        return root;
    }

    if(key<root->key)
    {
        root->left=delete(root->left,key);
    }
    else if(key>root->key)
    {
        root->right=delete(root->right,key);
    }
    else 
    {
        if(root->left==NULL)
        {
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node*temp=root->left;
            free(root);
            return temp;
        }
    
    struct node* temp=min(root->right);
    root->key=temp->key;

    root->right=delete(root->right,temp->key);
    }
    return root;
}

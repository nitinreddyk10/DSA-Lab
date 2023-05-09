/*
Create a complete binary tree in a level order fashion. Take the integer value from the user for each node
of BT. Perform the following operations on a created binary tree:
1. Show the Preorder/inorder/level/Postorder order traversal for the generated tree. (Recursive Function)
2. Check if a given Binary Tree is SumTree (Sumtree:-is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree).
3. Check whether your binary tree is a complete binary tree or not.
4. Check if two nodes are cousins in a Binary Tree.
5. Find a sum of subtree having maximum sum in a tree.
6. Find the sum of all nodes on the longest path from  root to leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node*left;
    int data;
    struct node*right;
};

struct node*create()
{
    struct node*newnode=malloc(sizeof(struct node));
    int x;
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data=x;
    
    printf("Left kid of %d ??\n",x);
    newnode->left=create();
    
    printf("Right kid of %d ??\n",x);
    newnode->right=create();
    
    return newnode;
}

void inorder(struct node*root)
{
    if(root==0)
    {
        return;
    }
        inorder(root->left);
        printf(" %d ",root->data);
        inorder(root->right);
}

void preorder(struct node*root)
{
    if(root==0)
    {
        return;
    }
        printf(" %d ",root->data);
        preorder(root->left);
        preorder(root->right);
}
void postorder(struct node*root)
{
    if(root==0)
    {
        return;
    }
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->data);
}

int heighttree(struct node*root)
{
    int height;
    struct node*newnode=root;
    if(newnode==NULL)
    return 0;
    
    int left=heighttree(newnode->left);
    int right=heighttree(newnode->right);
    
    if(left>=right)
    {
    height=left+1;
    //printf(" height x %d \n",height);
    }
    else 
    {
     height=right+1;
    // printf(" height x %d \n",height);
    }
  
    return height;
}

void levelorder(struct node*root,int height)
{
    int level=height-1;
    if(root==NULL)
    return;
    
    if(level==0)
    {
        printf("%d",root->data);
        printf("\n");
    }
    
    if(level>0)
    {
        levelorder(root->left,level-1);
        levelorder(root->right,level-1);
    }
}

int sum(struct node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return (sum(root->left) + root->data + sum(root->right));
}

int issumtree(struct node*root)
{
    int l,r;
    l=sum(root->left);
    r=sum(root->right);
    
    if((root==NULL || (root->left==NULL && root->right==NULL))||((root->data == l+r) &&(issumtree(root->left))  && issumtree(root->right)))
    return 1;
    else
    return 0;
}

int main()
{
    printf("At any point,to enter null node,enter-1\n");
    printf("Enter root element\n");
    struct node*root=create();
    
    printf("\nInfix is : ");
    inorder(root);
    printf("\nPrefix is : ");
    preorder(root);
    printf("\nPostfix is : ");
    postorder(root);
    
    int h=heighttree(root);
    printf("\nheight=%d\n",h);
    
    printf("rootdata:\n");
    for(int k=0;k<=h;k++)
    {
        levelorder(root,k);
    }
    
    if(issumtree(root)==1)
    {
        printf("\nIt is sum tree\n");
    }
    else
    {
        printf("\nIt is not sum tree\n");
    }
    
    int l,r;
    l=sum(root->left);
    r=sum(root->right);
    
    if(l>=r)
    {
        printf("Left subtree has maxsum and it id %d",l);
    }
    else
    {
        printf("Right subtree has maxsum and it id %d",r);
    }
    return 0;
}
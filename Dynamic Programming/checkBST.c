#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int val)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}
int minValue(struct node* node)
{
    if(node==NULL)
        return INT_MAX;
    int minLeft = minValue(node->left);
    int minRight = minValue(node->right);
    return min(node->data, min(minLeft, minRight));
}
int maxValue(struct node* node)
{
    if(node==NULL)
        return INT_MIN;
    int maxLeft = maxValue(node->left);
    int maxRight = maxValue(node->right);
    return max(node->data, max(maxLeft, maxRight));
}
int isBST(struct node* node)
{
    if(node == NULL)
        return 1;
    
    if(node->left == NULL || maxValue(node->left)>node->data)
        return 0;
    if(node->right == NULL || maxValue(node->right)>node->data)
        return 0;
    if(!isBST(node->left) || !isBST(node->right))
        return 0;
    return 1;
}

int main()
{
    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->right->left = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
 
    // Function call
    if (isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct node
{
    int val;
    struct node* left;
    struct node* right;
};

void Tree2DLL(struct node* root, struct list* head)
{
    if(root=NULL)
        return NULL;
    else
    {
        struct list* prev=NULL;


    }
    
}

struct node* createNode(int v)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->val=v;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return createNode(key);
    if (key < node->val) node->left = insert(node->left, key);
    else if (key > node->val) node->right = insert(node->right, key);
    return node;
}

int main()
{
    int n,v,h;
    scanf("%d",&n);
    struct node* tree = NULL;
    struct list* head = NULL;
    while((n--)>0)
    {
        scanf("%d",&v);
        tree=insert(tree,v);
    }
    head = Tree2DLL(tree, &head);
    

    return 0;
}

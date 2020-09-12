#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node* left;
    struct node* right;
};
int max(int a, int b)
{
    return a>b?a:b;
}
void dfs(struct node* root)
{
    if(root==NULL)
        return ;
    printf("%d ", root->val);
    dfs(root->left);
    dfs(root->right);
}
void printGivenLevel(struct node* root, int level)
{
    if(root==NULL)
        return ;
    if(level==1)
        printf("%d ", root->val);
    else if(level>1)
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
}
void bfs(struct node* root, int h)
{
    for(int i=1;i<=h;i++)
    {
        // printf("\nLevel %d: ",i);
        printGivenLevel(root, i);
    }
}
int getHeight(struct node* root)
{
    if(root==NULL)
        return 0;
    else
    {
        // printf("%d ",root->val);
        return (max(getHeight(root->left),getHeight(root->right))+1);
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
    /* If the tree is empty, return a new node */
    if (node == NULL) return createNode(key);
    /* Otherwise, recur down the tree */
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}
int main()
{
    int n,v,h;
    scanf("%d",&n);
    struct node* tree =NULL;
    while(n-->0)
    {
        scanf("%d",&v);
        tree=insert(tree,v);
    }
    printf("DFS Traversal: Inorder\n");
    dfs(tree);
    h=getHeight(tree);
    printf("\nTree hieght is %d\n",h);
    printf("BFS Traversal: \n");
    bfs(tree, h);
    return 0;
}

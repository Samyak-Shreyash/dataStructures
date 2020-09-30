#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node* left;
    struct node* right;
};

void tree2DLL(struct node* root, struct node** head)
{

    if(root == NULL)
    return ;
    else
    {
        static struct node* prev = NULL;
        tree2DLL(root->left, head);
        if(prev == NULL)
            *head = root;
        else
        {
            prev->right= root;
            root->left=prev;
        }
        prev= root;
        tree2DLL(root->right, head);
    }
    
}

struct node* getList(struct node* root)
{
    struct node* head = NULL;
    tree2DLL(root, &head);
    return head;
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

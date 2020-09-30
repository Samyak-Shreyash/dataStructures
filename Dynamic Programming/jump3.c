/*
Program to determine minimum number of jumps required to move from startto end of array
*/

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue* next;
};

struct queue* createNode(int v)
{
    struct queue* newNode =(struct queue*)malloc(sizeof(struct queue));
    newNode->data =v;
    newNode->next=NULL;
    return newNode;
}

struct queue* push(struct queue** visited, int v)
{
    struct queue* temp = *visited;
    if(temp==NULL)
    *visited=createNode(v);
    else
    {
        while(temp->next != NULL)
        temp=temp->next;
        temp->next=createNode(v);
    }

    return *visited;
}

int checkVisited(struct queue* visited, int v)
{
    while(visited != NULL)
    {
        if(visited->data==v)
            return 1;
        visited = visited->next;
    }
    return 0;
}

int getJumps(struct queue** visited, int* arr, int n, int strt)
{
    // printf("%d ",strt);
    if(strt>=n || strt<0 || checkVisited(*visited, strt))
        return 0;
    if(arr[strt]== 0)
        return 1;
    // printf("->");
    push(visited,strt);
    return getJumps(visited, arr,n,strt+arr[strt]) || getJumps(visited, arr,n,strt-arr[strt]);   
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i,strt,j;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&strt);
    struct queue* visited = NULL;
    
    printf("%d\n",getJumps(&visited, arr,n,strt));
    return 0;
}
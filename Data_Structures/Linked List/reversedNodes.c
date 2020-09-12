#include<stdio.h>
#include<stdlib.h>

struct node {
int val;
struct node* next;
};

void printList(struct node* head)
{
    printf("\n");
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->val);
        temp=temp->next;
    }
}
struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val= v;
    newNode->next=NULL;
    
    return newNode;
}

struct node* reverseNode(struct node** head)
{
    struct node* prev= NULL;
    struct node* temp= *head;
    struct node* next= NULL;
    while(temp!=NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev=temp;
        temp=next;
    }
    *head= prev;
}

struct node* appendNode(struct node** head, int v)
{
    if(*head==NULL)
    {
        *head=createNode(v);
        return *head;
    }
    
    struct node* temp = *head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = createNode(v);
    return *head;   
}

int main()
{
    struct node* head = NULL;
    int v = 1;
    scanf("%d",&v);
    while (v>0)
    {
        head= appendNode(&head, v);
        scanf("%d",&v);
        
    }
    printf("Reversed Nodes \n");
    reverseNode(&head);
    printList(head);
    return 0;
}
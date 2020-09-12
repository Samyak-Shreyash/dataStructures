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

struct node* detectLoop(struct node** head)
{
    if(*head==NULL)
        return *head;
    struct node* slow= *head;
    struct node* fast= slow->next;
    while(fast!=NULL && slow!= fast)
    {
        slow=slow->next;
        fast=fast->next;
        while(fast!=NULL)
            fast=fast->next;
    }
    return slow;
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
    detectLoop(&head);
    printList(head);
    return 0;
}
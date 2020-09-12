#include<stdio.h>
#include<stdlib.h>

struct node {
int val;
struct node* next;
};

void printList(struct node* head)
{
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

int getmiddleNode(struct node* head)
{
    struct node* fast= head;
    struct node* slow= head;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow = slow->next;
        }    
    }
    return slow->val;
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
    printf("Middle Node Val: %d\n",getmiddleNode(head));
    printList(head);
    return 0;
}
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

struct node* detectMerge(struct node** head1, struct node ** head2)
{
    if(*head1==NULL)
        return *head1;
    struct node* slow= *head1;
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
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    int v = 1;
    printf("Get Values for Linked List 1");
    scanf("%d",&v);
    while (v>0)
    {
        head1= appendNode(&head1, v);
        scanf("%d",&v);       
    }
    printf("Get Values for Linked List 2");
    scanf("%d",&v);
    while (v>0)
    {
        head1= appendNode(&head2, v);
        scanf("%d",&v);       
    }
    printf("Merge Node \n");
    printList(detectMerge(&head1, &head2));
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node {
int val;
struct node* next;
};

void printList(struct node* head)
{
    printf("\nPrinting\n");
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

struct node* dequeue(struct node** head)
{
    printf("\nDequeuing");
    if(*head==NULL || (*head)->next == NULL)
        return NULL;
    
    *head=(*head)->next;
    return *head;
}

struct node* enqueue(struct node** head)
{
    int v;
    printf("\nEnter Value: ");
    scanf("%d",&v);
    
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
    int loop = 1,ch;
    while (loop)
    {
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = enqueue(&head);
            break;
        case 2:
            head = dequeue(&head);
            break;
        case 3:
            printList(head);
            break;
        default:
            loop=0;
        }       
    }
    return 0;
}
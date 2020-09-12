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

struct node* pop(struct node** head)
{
    if(*head==NULL || (*head)->next == NULL)
        return NULL;
    
    *head=(*head)->next;
    return *head;
}

struct node* push(struct node** head)
{
    int v;
    scanf("%d",&v);
    struct node *queue = *head;
    *head=createNode(v);
    (*head)->next=queue;
    return *head;
}

int main()
{
    struct node* head = NULL;
    int loop = 1,ch;
    while (loop)
    {
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            head = push(&head);
            break;
        case 2:
            head = pop(&head);
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
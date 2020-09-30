/*
Program to check if a Linked List is a Palindrome
*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
void printList(struct ListNode* head, struct ListNode* EndNode)
{
    printf("\nLinked List: ");
    while(head!=EndNode)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}
int checkPalindrome(struct ListNode* head, struct ListNode* EndNode)
{
    if(head==NULL||head->next==NULL)
        return 1;
    printList(head,EndNode);
    struct ListNode* temp= head;
        while((temp->next)->next!=EndNode)
        {
            temp=temp->next;
        }
    if((temp->next)->val==(head)->val)
    {
        temp->next=NULL;
        return checkPalindrome(head->next,temp);
    }
        return 0;
}
int isPalindrome(struct ListNode* head) {
    struct ListNode* End;
    End=NULL;
    return checkPalindrome(head,End);
}
int main()
{
    struct ListNode* head= NULL;
    struct ListNode* node1= NULL;
    struct ListNode* node2= NULL;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    node1= (struct ListNode*)malloc(sizeof(struct ListNode));
    node2= (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=1;
    head->next=node1;
    node1->val=2;
    node1->next=node2;
    node2->val=1;
    node2->next=NULL;
    printf("%d ",isPalindrome(head));
    return 0;
}

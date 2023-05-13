#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp;
void create(int element)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!!");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (head == NULL)
    {
        temp = head = newNode;
    }
    else
    {

        temp->next = newNode;
        temp = newNode;
    }
}

void display()
{
    temp=head;
    while (temp!=NULL)

    {
      printf(" %d",temp->data);
      temp=temp->next;
    }
    
}
void getlength()
{
    int len = 0;
    temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    printf("\nLength of node is: %d", len);
}
int main()
{
    int n, choice = 1;
    while (choice == 1)
    {

        printf("\nEneter element to be inserted in list : ");
        scanf("%d", &n);
        create(n);
        printf("\nDo you want to insert more element (yes Press 1) : ");
        scanf("%d", &choice);
    }
    display();
    getlength();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
// function for creation of linked list
void createlist()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int choice = 1;
    head = NULL;
    while (choice)
    {
        printf("\n Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("\n Do you want to add more nodes? (0/1): ");
        scanf("%d", &choice);
    }
}
// function for deletion at begin
void delAtbeg()
{
    struct node *newnode;

    // newnode = (struct node *)malloc(sizeof(struct node));
    // newnode->data = 0;
    if (head == NULL)
    {
        printf("\nLinkedlist is Empty!!");
        return;
    }
    newnode->next = head->next;
    head = newnode->next;
    free(newnode);
}

// function for deletion at end
voiddelAtend()
{
    struct node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("\nLinkedlist is Empty!!");
        return;
    }
    while (temp->next != 0)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    free(temp);
}
// function for deletion at a position
void delAtpos()
{
    if (head == NULL)
    {
        printf("\nLinkedlist is Empty!!");
        return;
    }
    int pos;
    printf("\nEnter the postion of deletion: ");
    scanf("%d", &pos);
    struct node *temp, temp1;
    temp = temp1 = head;
    for (int i = 0; i < pos - 1 && temp != 0; i++)
    {
        temp = temp->next;
        temp1 = temp1->next;
    }
    temp1 = temp1->next;
    temp->next = temp1->next;
    free(temp);
    free(temp1);
}

// function for printing linked list
void printlist()
{
    if (head == NULL)
    {
        printf("\nLinkedlist is Empty!!");
        return;
    }
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    printf("Enter Your choice:\n1)Create list\n2)deletion at begining\n3)deletion at end\n4)deletion at a position");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        createlist();
        break;
    case 2:
        delAtbeg();
        break;
    case 3:
        delAtend();
        break;
    case 4:
        delAtpos();
        break;
    default:
        exit;
    }

    return 0;
}

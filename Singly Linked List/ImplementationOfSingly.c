#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
//creating a linked list...
    struct node *head, *newnode, *temp;
    int choice,count=0;
    head = 0;
    while (choice)
    {

      
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter element to be inserted in node: ");
        scanf("%d", &newnode->data);

        // newnode->data = data;
        newnode->next = 0;

        if (head == 0)
        {
             head = temp=newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nDo you want to add more nodes?(0/1): ");
        scanf("%d", &choice);
    }
//printing linkedlist--
    temp = head;
    while (temp != 0)
    {
        printf("\nData is : %d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\nNo. of nodes in linked-list is: %d",count);
 free(newnode);
return 0;
}

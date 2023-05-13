#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *temp, *tail, *newNode;
head = NULL;

// create a doubly linked list
void create_list()
{
    int choice = 1;
    do
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("memory allocation failed");
            exit(0);
        }
        printf("Enter the data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("\n Element Inserted Sucessfully");
        printf("\n Do you want to insert more element (0/1) : ");
        scanf("%d", &choice);
    } while (choice != 1);
}

// function to displaya doubly linkedList
void display_list()
{
    temp = head;
    if (head == NULL)
    {
        printf("\nList is empty");
        exit(0);
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
// freelist and exit
void free_list()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
}
// function for deletion from begining

void deleteAtbeg()
{
    temp = head;
    if (head == NULL)
    {
        printf("List is Empty Bruh!!");
        exit(0);
    }
    else
    {
        head = head->next;
        head->next->prev = NULL;
        free(temp); 
    }
    printf("\n Element deleted Sucessfuly!!");
}

int main()
{
    int option;
    while (1)
    {
        printf("\n1. Create \n2. Display \n3.free_list or exit\n4 delete At Begining\n5. delete At end\n6. delete At a position\n7. delete  after Position\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create_list();
            break;
        case 2:
            display_list();
            break;
        case 3:
            free_list();
            exit(0);
        case 4:
            deleteAtbeg();
            break;
        case 5:
            deleteAtend();
            break;
        case 6:
            deleteAtPos();
            break;
        case 7:
            deleteAfterPos();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

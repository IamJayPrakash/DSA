/*#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *temp, *tail, *newNode;
head = NULL;
tail=NULL;

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

    if (head == NULL)
    {
        printf("List is Empty Bruh!!");
        exit(0);
    }
    else
    {
        temp = head;

        head = head->next;
        head->prev = NULL; // or temp->next=0;

        free(temp);
    }
    printf("\n Element deleted Sucessfuly!!");
}
// function for deletion at end
void deleteAtend()
{
    if (head == NULL) // or tail==NULL
    {
        printf("List is Empty Bruh!!");
        exit(0);
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    printf("\n Element deleted Sucessfuly!!");
}
// function for deletion from a position
void deleteAtPos()
{
    if (head == NULL)
    {
        printf("List is Empty Bruh!!");
        exit(0);
    }
    else
    {
        int pos;

        printf("\nEnter the position : ");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("Invalid Position");
            exit(0);
        }
        else if (pos == 1)
        {
            deleteAtbeg();
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        printf("\n deletion sucessfull ho gya!");
    }
}
//main function
int main()
{
    int option;
    while (1)
    {
        printf("\n1. Create \n2. Display \n3.free_list or exit\n4 delete At Begining\n5. delete At end\n6. delete At a position\n\n");
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
        // case 7:
        //     deleteAfterPos();
        //     break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

// Function to create a doubly linked list
void createList()
{
    int choice = 1;

    while (choice == 1)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed");
            exit(0);
        }

        printf("Enter the data: ");
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

        printf("Element inserted successfully\n");
        printf("Do you want to insert more elements? (0/1): ");
        scanf("%d", &choice);
    }
}

// Function to display the doubly linked list
void displayList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the doubly linked list and exit
void freeList()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    exit(0);
}

// Function to delete a node from the beginning of the list
void deleteAtBegin()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }
        free(temp);
        printf("Element deleted successfully\n");
    }
}

// Function to delete a node from the end of the list
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }
        free(temp);
        printf("Element deleted successfully\n");
    }
}

// Function to delete a node from a specific position in the list
void deleteAtPosition()
{
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int pos;
        printf("Enter the position: ");
        scanf("%d", &pos);

        if (pos < 1)
        {
            printf("Invalid position\n");
        }
        else if (pos == 1)
        {
            deleteAtBegin();
        }
        else
        {
            struct node *current = head;
            int i = 1;
            while (i < pos && current != NULL)
            {
                current = current->next;
                i++;
            }

            if (current == NULL)
            {
                printf("Invalid position\n");
            }
            else
            {
                current->prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                free(current);
                printf("Element deleted successfully\n");
            }
        }
    }
}

// Main function
int main()
{
    int option;
    while (1)
    {
        printf("\n1. Create\n2. Display\n3. Free list and exit\n4. Delete at the beginning\n5. Delete at the end\n6. Delete at a position\n\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            createList();
            break;
        case 2:
            displayList();
            break;
        case 3:
            freeList();
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

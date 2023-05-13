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

void create()
{
    int ch = 1;
    do
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

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

        printf("Element inserted successfully!!\n");
        printf("Do you want to add more data (press 1)): ");
        scanf("%d", &ch);
    } while (ch == 1);
}

void display()
{
    struct node *temp = head;
    if (temp == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    printf("Elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

int main()
{
    int option;
    while (1)
    {
        printf("\n1. Create \n2. Display \n3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            free_list();
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

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

// insertion at begining

void insertBeg()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        tail = head = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("\nNode Inserserted at begining Sucesssfully\n");
}

//insertion at end

void insertAtend()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); 
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
    printf("\n Element Inserted at end sucessfully\n");
}

// Insert at positon
void insertAtPos()
{
    int pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("\nInvalid Position Bruh !!");
        exit(1);
    }
    else if (pos == 1)
    {
        insertBeg();
    }
    else
    {
        int i = 1;
        struct node *temp = head;

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
    printf("\n Element inserted Sucessfully!!");
}

// Insert after a positon
void insertAfterPos()
{
    int pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("\nInvalid Position Bruh !!");
        exit(1);
    }
    else
    {   int i = 1;
        struct node *temp = head;
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        newNode->next->prev = newNode;
        temp->next = newNode;
       
    }
    printf("\nElement inserted Sucessfully!!");
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
        printf("\n1. Create \n2. Display \n3.free_list or exit\n4.Insert at Begining\n5.Insert at end\n6.Insert at a position\n7.Insert after Position\n\n");
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
        case 4:
            insertBeg();
            break;
        case 5:
            insertAtend();
            break;
        case 6:
            insertAtPos();
            break;
        case 7:
            insertAfterPos();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}

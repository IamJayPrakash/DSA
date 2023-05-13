
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Insert a node at the beginning of the linked list
void insertAtBeginning(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the linked list
void insertAtEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node at a given position in the linked list
void insertAtPosition(struct node **head, int data, int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Print the linked list
void printLinkedList(struct node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
//------------------------------------------------MAIN FUNCTION-------------------------------------------
int main()
{
    struct node *head = NULL;

    // creating a linked list
    int n, i = 1;

    while (n)
    {
        int data;
        printf("Enter element for node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(&head, data);
        printf("want to add more nodes in the linked list (0/1): ");
        scanf("%d", &n);
        i++;
    }
    printLinkedList(head);

    // Insertion at the beginning
    int data;
    printf("Enter data to be inserted at the beginning: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);
    printLinkedList(head);

    // Insertion at the end
    printf("Enter data to be inserted at the end: ");
    scanf("%d", &data);
    insertAtEnd(&head, data);
    printLinkedList(head);

    // Insertion at a given position
    int position;
    printf("Enter the position for the new node: ");
    scanf("%d", &position);
    printf("Enter data to be inserted at position %d: ", position);
    scanf("%d", &data);
    insertAtPosition(&head, data, position);
    printLinkedList(head);

    return 0;
}

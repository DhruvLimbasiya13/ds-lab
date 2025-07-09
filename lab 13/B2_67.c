#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void insertAtFirst(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

int GCD(int a, int b)
{
    int min = (a < b) ? a : b;
    for (int i = min; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
    return 1;
}

void display()
{
    if (first == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    struct node *save = first;
    while (save != NULL)
    {
        printf("%d -> ", save->info);
        save = save->link;
    }
    printf("NULL\n");
}

void insertGcd()
{
    if (first == NULL || first->link == NULL)
    {
        printf("Not enough nodes to compute GCD.\n");
        return;
    }

    struct node *current = first;
    while (current != NULL && current->link != NULL)
    {
        struct node *next = current->link;
        int gcdVal = GCD(current->info, next->info);

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->info = gcdVal;
        newNode->link = next;
        current->link = newNode;

        current = next; // Move to next original node
    }
}

int main()
{
    int choice, a;
    while (1)
    {
        printf("\n1. Enter a new node\n2. Insert GCDs between nodes and display\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &a);
            insertAtFirst(a);
            display();
            break;

        case 2:
            insertGcd();
            display();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}

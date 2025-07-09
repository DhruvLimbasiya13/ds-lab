#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;

void InsertAtFirst(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;

    if (first == NULL)
    {
        first = newNode;
        newNode->link = NULL;
    }
    else
    {
        newNode->link = first;
        first = newNode;
    }

    printf("Info of first Node : %d\n", first->info);
}

void InsertAtLast(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
}

void sortNodes()
{
    if (first == NULL || first->link == NULL)
    {
        printf("List is empty or has only one node.\n");
        return;
    }

    struct node *end = NULL;

    while (end != first->link)
    {
        struct node *pred = NULL;
        struct node *save = first;

        while (save->link != end)
        {
            struct node *next = save->link;

            if (save->info > next->info)
            {
                struct node *temp = next->link;

                if (pred == NULL)
                {
                    next->link = save;
                    save->link = temp;
                    first = next;
                    pred = next;
                }
                else
                {
                    pred->link = next;
                    save->link = temp;
                    next->link = save;
                    pred = next;
                }
            }
            else
            {
                pred = save;
                save = save->link;
            }
        }

        end = save;
    }

    printf("\nSorted successfully.\n");
}

void swapAlternateNodes()
{
    if (first == NULL || first->link == NULL)
    {
        printf("List is too short to swap.\n");
        return;
    }//if

    struct node *prev = NULL;
    struct node *save = first;

    first = save->link;

    while (save != NULL && save->link != NULL)
    {
        struct node *next = save->link;
        struct node *nextNext = next->link;

        next->link = save;
        save->link = nextNext;

        if (prev != NULL)
        {
            prev->link = next;
        }//if

        prev = save;
        save = nextNext;
    }//while

    printf("Alternate nodes swapped successfully.\n");
}//swap

void DisplayAllNodes()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist.\n");
    }
    else
    {
        struct node *save = first;
        int i = 1;
        while (save != NULL)
        {
            printf("Value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        }
    }
}

void main()
{
    while (1)
    {
        printf("\n1. Insert a node at the front of the linked list.\n");
        printf("2. Display all nodes.\n");
        printf("3. Insert a node at the end of the linked list.\n");
        printf("4. Sort the linked list.\n");
        printf("5. Swap alternate nodes.\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice, x;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the info of new Node:\n");
            scanf("%d", &x);
            InsertAtFirst(x);
            break;

        case 2:
            DisplayAllNodes();
            break;

        case 3:
            printf("Enter the info of new Node:\n");
            scanf("%d", &x);
            InsertAtLast(x);
            break;

        case 4:
            sortNodes();
            break;

        case 5:
            swapAlternateNodes();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
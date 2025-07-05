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
    } // if
    else
    {
        newNode->link = first;
        first = newNode;
    } // else

    printf("Info of first Node : %d\n", first->info);

} // insert at first

void InsertAtLast(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->info = x;

    if (first == NULL)
    {
        newNode->link = first;
        first = newNode;

    } // if
    else
    {
        struct node *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        } // while

        save->link = newNode;
        newNode->link = NULL;

    } // else
} // insert at last

void removeDuplicate()
{
    if (first == NULL)
    {
        printf("Nodes don't exist.\n");
        return;
    }

    struct node *save = first;
    int flag = 0;

    while (save != NULL && save->link != NULL)
    {
        if (save->info == save->link->info)
        {
            struct node *next = save->link;
            save->link = next->link;
            free(next);
            flag = 1;
        }
        else
        {
            save = save->link;
        }
    }

    if (!flag)
    {
        printf("\nNo duplicate found.\n");
    }
}

void sortNodes()
{
    if (first == NULL || first->link == NULL)
    {
        printf("List is empty or has only one node.\n");
        return;
    } // if

    int swapped;
    struct node *save, *next;
    struct node *end = NULL;

    do
    {
        swapped = 0;
        save = first;

        while (save->link != end)
        {
            next = save->link;
            if (save->info > next->info)
            {
                int temp = save->info;
                save->info = next->info;
                next->info = temp;
                swapped = 1;
            } // if
            save = save->link;
        } // while
        end = save;
    } while (swapped); // do while
}

void DisplayAllNodes()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first;
        int i = 1;
        while (save != NULL)
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        } // while
    } // else
} // dislpay nodes

void main()
{
    while (1)
    {
        printf("\n1.Insert a node at the front of the linked list. \n2.Display all nodes.\n3.Insert a node at the end of the linked list.\n4.Remove duplicate(it will sort the link list first).\n5. exit\n Enter your Choice\n");
        int choice;
        scanf("%d", &choice);
        int x;

        switch (choice)
        {
        case 1:
            printf("enter the info of new Node :\n");

            scanf("%d", &x);
            InsertAtFirst(x);
            break;

        case 2:
            DisplayAllNodes();
            break;

        case 3:
            printf("enter the info of new Node :\n");
            scanf("%d", &x);
            InsertAtLast(x);
            break;

        case 4:
            sortNodes();
            removeDuplicate();
            break;

        case 5:
            exit(0);
        default:
            break;
        } // switch
    } // while
} // main
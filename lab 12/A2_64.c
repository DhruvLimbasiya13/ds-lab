#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
}; // struct

struct node *first = NULL;

void InsertAtFirst()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nenter the info of new node.\n");
    scanf("%d", &x);
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

void InsertAtLast()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nenter the info of new node.\n");
    scanf("%d", &x);
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

    printf("Info of last Node : %d\n", newNode->info);
} // insert at last

void DisplayAllNodes()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        printf("\n");
        struct node *save = first;
        int i = 1;
        while (save != NULL)
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        } // while
    } // else
} // display node

void reverseLinkList()
{
    if (first == NULL)
    {
        printf("Linked list does not exist.\n");
        return;
    } // if

    else
    {
        struct node *save = first;
        struct node *pred = NULL;
        struct node *next = NULL;

        while (save != NULL)
        {
            next = save->link;
            save->link = pred;
            pred = save;
            save = next;
        }//while
        first = pred;
    }//else
}//reverse

void main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert at front of link list.");
        printf("\n2.Insert at last of link list.");
        printf("\n3.Display Link List.");
        printf("\n4.Reverse a Link list.");
        printf("\n5.Exit.");
        printf("\nEnter your choice :  ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtFirst();
            break;
        case 2:
            InsertAtLast();
            break;
        case 3:
            DisplayAllNodes();
            break;
        case 4:
            reverseLinkList();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\ninvalid choice\n");
            break;
        }
    }
}
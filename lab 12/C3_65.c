#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *first = NULL;
int count = 0;

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
    count++;
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
    count++;
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

void replaceNode()
{
    if (count == 0)
    {
        printf("\nLinked list is empty.\n");
        return;
    } // if

    printf("\nEnter the position (k) to replace from both sides:\n");
    int k;
    scanf("%d", &k);

    if (k <= 0 || k > count)
    {
        printf("Invalid position. It must be between 1 and %d.\n", count);
        return;
    } // if

    int fromFront = k;
    int fromEnd = count - k + 1;

    struct node *front = first;
    for (int i = 1; i < fromFront; i++)
    {
        front = front->link;
    }// for

    struct node *end = first;
    for (int i = 1; i < fromEnd; i++)
    {
        end = end->link;
    } // for

    int temp = front->info;
    front->info = end->info;
    end->info = temp;
    printf("Replacement completed.\n");
} // replace the nodes

void main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert At first.");
        printf("\n2.Insert At last.");
        printf("\n3.Replace the Nodes.");
        printf("\n4.Display.");
        printf("\n5.Exit.");
        printf("\nEnter Choice : ");
        int x;
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
            replaceNode();
            break;
        case 4:
            DisplayAllNodes();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\ninvalid choice.\n");
            break;
        }
    }
}
#include <stdio.h>
#include <stdlib.h>


void menu();
void InsertAtFirst(int x);
void InsertAtLast(int x);
void DisplayAllNodes();
void DeleteFirstNode();
void DeleteAtLast();
void DeleteAtSpecifiedPosition(int Position);
void Count();

struct node
{
    int info;
    struct node *link;
}; // struct

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

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

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

    printf("Info of last Node : %d\n", newNode->info);
    printf("link of last Node : %d\n", newNode->link);

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

} // insert at last

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

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

} // display all nodes

void DeleteFirstNode()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first;
        first = save->link;
        save->link = NULL;

        free(save);
    } // else

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

} // delete first Nodes

void DeleteAtLast()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first;
        struct node *pred = save;
        while (save->link != NULL)
        {
            pred = save;
            save = save->link;
        } // while

        pred->link = NULL;

        free(save);

    } // else

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

} // delete at last

void DeleteAtSpecifiedPosition(int Position)
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if

    else
    {
        struct node *save = first;
        struct node *pred = save;
        while (Position)
        {
            pred = save;
            save = save->link;
            Position--;
        } // while

        pred->link = save->link;

        free(save);
    } // else

    printf("1. Go to back menu \n2. exit");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        menu();
        return;
    case 2:
        exit(0);
    default:
        break;
    } // switch case

} // Delete At Specified Position

void Count()
{
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first;

        int i = 1;
        while (save->link != NULL)
        {
            i++;
            save = save -> link;
        } // while
        printf("number of nodes : %d", i);
    } // else
}//count

void menu()
{
    printf("1.Insert a node at the front of the linked list. \n2. Display all nodes.\n3. Delete a first node of the linked list.\n4. Insert a node at the end of the linked list.\n5. Delete a last node of the linked list.\n6. Delete a node from specified position.\n7.count the number of Node\n8. exit\n Enter your Choice");
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
        DeleteFirstNode();
        break;

    case 4:
        printf("enter the info of new Node :\n");
        scanf("%d", &x);
        InsertAtLast(x);
        break;

    case 5:
        DeleteAtLast();
        break;

    case 6:
        printf("Enter the position of Node you want to Delete :");
        int position;
        scanf("%d", &position);
        DeleteAtSpecifiedPosition(position);
        break;

    case 7:
        Count();
        break;

    case 8 :
        exit(0);
    default:
        printf("please enter the valid number .");
        break;
    }//switch
}//menu

void main()
{
    menu();
}
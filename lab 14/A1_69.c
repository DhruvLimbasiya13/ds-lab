#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
struct node *last = NULL;

void insertAtFirst()
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    int x ;
    printf("\nEnter the info of new Node: \n");
    scanf("%d", &x);
    newNode->info = x;
    if (first == NULL)
    {
        first = last = newNode;
        newNode->link = newNode;
    }//if
    else
    {
        newNode->link = first;
        first = newNode;
        last->link = first;
    }//else
}//insert at first

void insertAtLast()
{
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    int x ;
    printf("\nEnter the info of new Node: \n");
    scanf("%d", &x);
    newNode->info = x;
    if (first == NULL)
    {
        first = last = newNode;
        last->link = first;
    }//if
    else
    {
        last->link = newNode;
        newNode->link = first;
        last = newNode;
    }//else
}//insert at last

void deleteNode()
{
    int x;
    printf("\nEnter the position to delete: \n");
    scanf("%d", &x);
    if (first == NULL)
    {
        printf("Empty List");
    }//if
    else if (first->link == NULL)
    {
        free(first);
        first = NULL;
    }//else if
    else
    {
        struct node *save = first;
        struct node *pred = save;
        while (x)
        {
            pred = save;
            save = save->link;
            x--;
        }//while
        pred->link = save->link;
        free(save);
    }//while
}//delete node

void display()
{
    if (first == NULL)
    {
        printf("\nEmpty List\n");
    }//if
    else
    {
        struct node *save = first;
        int i =1;
        do
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        } while (save != first);//do while
        
    }//else
}//display

void main()
{
    int ch, x;
    printf("Enter your choice\n");
    while (1)
    {
        printf("\n1.Insert a node at first\n2.Delete a node\n3.Insert a node at last\n4.Display all nodes\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            deleteNode();
            break;
        case 3:
            insertAtLast();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:printf("\ninvalid choice.\n");
            break;
        }//switch
    }//while
}//main
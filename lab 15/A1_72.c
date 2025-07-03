#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *first = NULL;
struct node *last = NULL;

void insertAtFirst()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the info of new node: \n");
    scanf("%d", &x);

    newNode->info = x;
    newNode->lptr = NULL;

    if (first == NULL)
    {
        newNode->rptr = NULL;
        first = last = newNode;
    } // if
    else
    {
        newNode->rptr = first;
        first->lptr = newNode;
        first = newNode;
    } // else

} // insert at first

void deleteAtSpecifiedPosition()
{
    int position, count = 0, i = 0;
    struct node *save = first;

    printf("\nEnter position of node you want to delete (starting from 0): \n");
    scanf("%d", &position);

    if (first == NULL)
    {
        printf("\nLinked list does not exist.\n");
        return;
    }//if

    while (save != NULL)
    {
        count++;
        save = save->rptr;
    }//while

    if (position < 0 || position >= count)
    {
        printf("\nInvalid position.\n");
        return;
    }//if

    save = first;

    if (position == 0)
    {
        if (first == last)
        {
            free(first);
            first = last = NULL;
        }// inner if
        else
        {
            first = first->rptr;
            first->lptr = NULL;
            free(save);//now save is pointing node which is sperated
        }//else
        return;
    }//outer if

    while (position)
    {
        save = save->rptr;
        position--;
    }//while

    if (save == last)
    {
        last = save->lptr;
        last->rptr = NULL;
    }//if
    else
    {
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
    }//else

    free(save);
}// delete at specified position

void insertAtLast(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the info of new node: \n");
    scanf("%d", &x);

    newNode->info = x;
    newNode->rptr = NULL;

    if (first == NULL)
    {
        newNode->lptr = NULL;
        first = last = newNode;
    } // if
    else
    {
        newNode->lptr = last;
        last->rptr = newNode;
        last = newNode;
    } // else
}//insert at last

void displayAllNodes(){
    if (first == NULL)
    {
        printf("\nlink list doesn't exit.\n");
    }//if
    else{
        struct node * save = first ;
        int i = 1;
        while (save != NULL)
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->rptr;
            i++;
        }//while
        
    }//else
    
}//display

void main()
{
    while (1)
    {
        int choice ;
        printf("\nEnter your choice\n");
        printf("1.Insert a node at first\n2.Delete a specific node\n3.Insert a node at last\n4.Display all nodes\n5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            deleteAtSpecifiedPosition();
            break;
        case 3:
            insertAtLast();
            break;
        case 4:
            displayAllNodes();
            break;
        case 5:
            exit(0);
            break;
        default:printf("\ninvalid choice.\n");
            break;
        }//switch
    }//while
}//main
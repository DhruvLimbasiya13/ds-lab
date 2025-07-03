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

void deleteAlternate()
{

    if (first == NULL)
    {
        printf("\nLinked list does not exist.\n");
        return;
    } // if
    else
    {
        struct node *save = first;
        int count = 0;

        while (save != NULL)
        {
            struct node *next = save->rptr;

            if (count % 2 != 0)
            {
                if (save->lptr != NULL)
                {
                    save->lptr->rptr = save->rptr;
                } // if

                if (save->rptr != NULL)
                {
                    save->rptr->lptr = save->lptr;
                } // if

                free(save);
            } // outer if

            save = next;
            count++;
        } // while
    } //else
}//delete alternate

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

void main(){
    while (1)
    {
        int choice ;
        printf("\nEnter your choice\n");
        printf("1.Insert a node \n2.Delete a alternate node\n3.display nodes\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtFirst();
            break;
        case 2:
            deleteAlternate();
            break;

        case 3: displayAllNodes();
            break;
        case 4:
            exit(0);
            break;
        default:printf("\ninvalid choice.\n");
            break;
        }//switch
    }//while
}//main

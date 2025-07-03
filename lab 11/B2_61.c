#include<stdio.h>
#include<stdlib.h>
struct node{
    int info ;
    struct node * link ;
};

struct node *first = NULL;

void enqueue()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nenter the info of new node.\n");
    scanf("%d",&x);

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

}//insert at first

void dequeue()
{
    if (first == NULL)
    {
        printf("Nodes don't exist.\n");
    }
    else if (first->link == NULL)  // Only one node case
    {
        free(first);
        first = NULL;
    }
    else
    {
        struct node *save = first;
        struct node *pred = NULL;

        while (save->link != NULL)
        {
            pred = save;
            save = save->link;
        }

        pred->link = NULL;
        free(save);
    }
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
}//display all nodes

void main(){
    while (1)
    {
        printf("\nenter choice\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:enqueue();
            break;
        
        case 2:dequeue();
            break;

        case 3:DisplayAllNodes();
            break;

        case 4:
            exit(0);
            break;
        default:
            printf("\ninvalid choice.\n");
            break;
        }
    }
    
}
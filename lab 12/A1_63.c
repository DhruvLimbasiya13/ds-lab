#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first1 = NULL;
struct node *first2 = NULL;

void InsertNewNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("enter info of new node :");
    scanf("%d", &x);

    newNode->info = x;

    if (first1 == NULL)
    {
        newNode->link = first1;
        first1 = newNode;

    } // if
    else
    {
        struct node *save = first1;
        while (save->link != NULL)
        {
            save = save->link;
        } // while

        save->link = newNode;
        newNode->link = NULL;

    } // else
} // insertNewNode

void DisplayAllNodes()
{
    if (first1 != NULL)
    {
        struct node *save1 = first1;
        int i = 1;
        printf("\nfirst link list :\n");
        while (save1 != NULL)
        {
            printf("value of Node %d : %d\n", i, save1->info);
            save1 = save1->link;
            i++;
        } // while
    }
    else
    {
        printf("\nlink list 1 is empty.\n");
    }

    if (first2 != NULL)
    {
        struct node *save2 = first2;
        int i = 1;
        printf("\nsecond link list :\n");
        while (save2 != NULL)
        {
            printf("value of Node %d : %d\n", i, save2->info);
            save2 = save2->link;
            i++;
        } // while
    }
    else
    {
        printf("\nlink list 2 is empty.\n");
    }
} // display all nodes

void CreateNewList()
{
    if (first1 == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first1;
        while (save != NULL)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode->info = save->info;
            newNode->link = NULL;
            if (first2 == NULL)
            {
                first2 = newNode;
            }
            else
            {
                struct node *temp = first2;
                while (temp->link != NULL)
                {
                    temp = temp->link;
                }
                temp->link = newNode;
            }//else
            save = save -> link ;
        } // while
    } // else
}

void main()
{
    while (1)
    {
        printf("\n1.enter new node\n2.display\n3.copy into new link list\n4.exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertNewNode();
            break;
        case 2:
            DisplayAllNodes();
            break;
        case 3:
            CreateNewList();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}
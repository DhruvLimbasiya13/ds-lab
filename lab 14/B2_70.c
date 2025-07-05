#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first1 = NULL;
struct node *last1 = NULL;
struct node *first2 = NULL;
struct node *last2 = NULL;
int count = 0 ;


void insertAtfirst1()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the info of new Node: \n");
    scanf("%d", &x);
    newNode->info = x;
    if (first1 == NULL)
    {
        first1 = last1 = newNode;
        newNode->link = newNode;
    } // if
    else
    {
        newNode->link = first1;
        first1 = newNode;
        last1->link = first1;
    } // else
    count++;
} // insert at first1

void insertAtlast1()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the info of new Node: \n");
    scanf("%d", &x);
    newNode->info = x;
    if (first1 == NULL)
    {
        first1 = last1 = newNode;
        last1->link = first1;
    } // if
    else
    {
        last1->link = newNode;
        newNode->link = first1;
        last1 = newNode;
    } // else
    count++;
} // insert at last1

void SplitList()
{
    if (count == 0)
    {
        printf("\nFirst link list is empty.\n");
    } // if
    else if (count == 1)
    {
        printf("\nFirst link list has only one node so can't split into half.\n");
    } // else if
    else
    {
        int temp = ceil((double)count/2);
        struct node * save = first1;
        struct node * pred = NULL;
        while (temp)
        {
            pred = save ;
            save = save -> link ;
            temp -- ;
        }
        first2 = save ;
        pred -> link = first1;
        last1 = pred ;

        while (save -> link != first1 )
        {
            save = save -> link ;
        }
        last2 = save ;
        last2 -> link = first2;
        
        
    } // while
    printf("\nsplit successfully.\n");
} // delete node

void display()
{
    if (first1 == NULL)
    {
        printf("\nFirst link list is Empty.\n");
    } // if
    else
    {
        struct node *save = first1;
        int i = 1;
        printf("\nFirst link list.\n");
        do
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        } while (save != first1); // do while

    } // else

    if (first2 == NULL)
    {
        printf("\nSecond link list is Empty.\n");
    } // if
    else
    {
        struct node *save = first2;
        int i = 1;
        printf("\nSecond link list.\n");
        do
        {
            printf("value of Node %d : %d\n", i, save->info);
            save = save->link;
            i++;
        } while (save != first2); // do while

    } // else
} // display

void main()
{
    int ch, x;
    printf("Enter your choice\n");
    while (1)
    {
        printf("\n1.Insert a node at first1\n2.Split link list\n3.Insert a node at last1\n4.Display all nodes\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertAtfirst1();
            break;
        case 2:
            SplitList();
            break;
        case 3:
            insertAtlast1();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\ninvalid choice.\n");
            break;
        } // switch
    } // while
} // main
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node *insertNewNode(struct node *temp, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;

    if (temp == NULL)
    {
        temp = newNode;
        return temp;
    } // if
    else
    {
        struct node *save = temp;
        while (save->link != NULL)
        {
            save = save->link;
        } // while
        save->link = newNode;
    } // else
    return temp;
} // insert at end

struct node *even1(struct node *even, struct node *first)
{
    if (first == NULL)
    {
        printf("\nempty link list .\n");
        return first;
    }
    else
    {
        struct node *save = first;
        while (save != NULL)
        {
            if (save->info % 2 == 0)
            {
                even = insertNewNode(even, save->info);
            } // if
            save = save -> link;
        } // while

    } // else
    return even;
} // even

struct node *odd1(struct node *odd, struct node *first)
{
    if (first == NULL)
    {
        printf("\nempty link list .\n");
        return first;
    }
    else
    {
        struct node *save = first;
        while (save != NULL)
        {
            if (save->info % 2 != 0)
            {
                odd = insertNewNode(odd, save->info);
            } // if
            save = save-> link;
        } // while

    } // else
    return odd;
} // odd

void display(struct node *temp)
{
    if (temp == NULL)
    {
        printf("\nEmpty link list.\n");
    } // if
    else
    {
        struct node *save = temp;
        int i = 1;
        do
        {
            printf("value of %d node : %d \n", i, save->info);
            save = save-> link;
            i++;
        } while (save != NULL); // while

    } // else

} // display

void main()
{
    int choice, x;
    struct node *first = NULL;
    struct node *odd = NULL;
    struct node *even = NULL;
    while (1)
    {
        printf("\n1.insert node in first link list.\n2.create and display even link list \n3.create and display odd link list.\n4.display first link list.\n5.exit\nEnter your choice.");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the info of node : ");
            scanf("%d", &x);
            first = insertNewNode(first, x);
            break;
        case 2:
            even = even1(even, first);
            display(even);
            break;

        case 3:
            odd = odd1(odd, first);
            display(odd);
            break;
        case 4:
            display(first);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}
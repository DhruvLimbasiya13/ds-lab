#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node *link;
};
struct node *first1 = NULL, *first2 = NULL, *first3 = NULL;

struct node *insertNewNode(struct node *temp, int coefficient, int exponent)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->coeff = coefficient;
    newNode->expo = exponent;
    newNode->link = NULL;

    if (temp == NULL)
    {
        temp = newNode;
    } // if
    else
    {
        struct node *save = temp;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    } // else

    return temp;
} // insert new node

void display()
{
    if (first1 != NULL)
    {
        struct node *save1 = first1;
        printf("\nFirst Linked List:\n");
        while (save1 != NULL)
        {
            printf("%dx^%d", save1->coeff, save1->expo);
            save1 = save1->link;
            if (save1)
            {
                printf(" + ");
            }
        }//while

        printf("\n");
    } // if
    else
    {
        printf("\nLinked list 1 is empty.\n");
    } // else

    if (first2 != NULL)
    {
        struct node *save2 = first2;
        printf("\nSecond Linked List:\n");
        while (save2 != NULL)
        {
            printf("%dx^%d", save2->coeff, save2->expo);
            save2 = save2->link;
            if (save2)
            {
                printf(" + ");
            }

        } // while
        printf("\n");
    } // if
    else
    {
        printf("\nLinked list 2 is empty.\n");
    } // else

    if (first3 != NULL)
    {
        struct node *save3 = first3;
        printf("\nAddition : \n");
        while (save3 != NULL)
        {
            printf("%dx^%d", save3->coeff, save3->expo);
            save3 = save3->link;
            if (save3)
            {
                printf(" + ");
            }
        } // while
        printf("\n");
    } // if
    else
    {
        printf("\nAddition not happen.\n");
    } // else
} // diplay

struct node *addPolynomial(struct node *first3)
{
    struct node *ptr1 = first1, *ptr2 = first2;

    while (ptr1 && ptr2)
    {
        if (ptr1->expo == ptr2->expo)
        {
            first3 =insertNewNode(first3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        } // if
        else if (ptr1->expo > ptr2->expo)
        {
            first3 = insertNewNode(first3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        } // else if
        else
        {
            first3 = insertNewNode(first3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        } // else
    } // while

    while (ptr1)
    {
        first3 = insertNewNode(first3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }

    while (ptr2)
    {
        first3 = insertNewNode(first3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }

    return first3;
} // add polynomial

void main()
{
    int choice, coeff, expo;

    while (1)
    {
        printf("\n--- Polynomial Menu ---\n");
        printf("1. Insert in First Polynomial\n");
        printf("2. Insert in Second Polynomial\n");
        printf("3. Display Polynomials\n");
        printf("4. Add Polynomials\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coefficient for first polynomial: ");
            scanf("%d", &coeff);
            printf("Enter exponent for first polynomial: ");
            scanf("%d", &expo);
            first1 = insertNewNode(first1, coeff, expo);
            break;
        case 2:
            printf("Enter coefficient for second polynomial: ");
            scanf("%d", &coeff);
            printf("Enter exponent for second polynomial: ");
            scanf("%d", &expo);
            first2 = insertNewNode(first2, coeff, expo);
            break;
        case 3:
            display();
            break;
        case 4:
            first3 = NULL;
            first3 = addPolynomial(first3);
            printf("Polynomials added successfully.\n");
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
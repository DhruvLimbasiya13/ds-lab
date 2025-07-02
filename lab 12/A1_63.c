#include<stdio.h>
#include<stdlib.h>

struct node {
    int info ;
    struct node * link ;
};

struct node * first = NULL;
struct node * first2 = NULL;

void InsertNewNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int x ;
    printf("enter info of new node :");
    scanf("%d",&x);

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
}//insertNewNode

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
}//display all node

void CreateNewList(){
    if (first == NULL)
    {
        printf("Nodes doesn't exist .\n");
    } // if
    else
    {
        struct node *save = first;
        struct node * temp = first2;
        while (save != NULL)
        {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            newNode -> info = save -> info;
            newNode -> link = NULL;
            if(first2 == NULL){
                first2 = newNode ;
            }
            else{
                temp -> link = newNode;
                temp = temp -> link;
            }
        } // while
    } // else
}

void menu(){
    printf("\n1.enter new node\n2.display\n3.copy into new link list\n4.exist\n");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:InsertNewNode(); break;
    case 2:DisplayAllNodes(); break;
    case 3:CreateNewList(); break;
    case 4:exit(0); break;
    default:
        break;
    }
}

void main (){
    menu();

}
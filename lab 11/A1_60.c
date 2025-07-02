#include<stdio.h>
#include<stdlib.h>
struct node{
    int info ;
    struct node * link ;
};

struct node *first = NULL;

void push()
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

void pop()
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

} // delete first Nodes

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
        printf("\nenter choice\n1.push\n2.pop\n3.display\n4.exit\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:push();
            break;
        
        case 2:pop();
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
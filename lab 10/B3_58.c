#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link ;
};

struct node *first1 = NULL ;
struct node *first2 = NULL ;
int count = 0;

struct node * InsertNewNode(struct node * temp){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nenter info of new Node :\n");
    int x;
    scanf("%d",&x);
    newNode->info = x;

    if (temp == NULL)
    {
        newNode->link = temp;
        temp = newNode;

    } // if
    else
    {
        struct node *save = temp;
        while (save->link != NULL)
        {
            save = save->link;
        } // while

        save->link = newNode;
        newNode->link = NULL;

    } // else
    count++;
    return temp;
}//insert new node

void Check(){
    if (count%2!=0)
    {
        printf("\nlink lists are not same.\n");
    }//if
    else if (count == 0)
    {
        printf("\nno link list exist.\n");
    }//else if
    else{
        struct node *save1 = first1;
        struct node *save2 = first2;
        int flag = 0;
        while (save1 != NULL && save2 !=NULL)
        {
            if (save1 -> info != save2 -> info)
            {
                flag = 1;
                break;
            }//if
            
            save2 = save2 -> link;
            save1 = save1 -> link;
        } // while

        if (flag == 0)
        {
            printf("\nlink lists are same.\n");
        }//if
        else{
            printf("\nlink lists are not same.\n");
        }//else
    }//else
    
}//check

void Display(){
        if (first1 != NULL)
        {
            struct node *save1 = first1;
            int i = 1;
            printf("\nfirst link list :\n");
            while (save1 != NULL)
            {
                printf("value of Node %d : %d\n", i, save1->info);
                save1 = save1 -> link;
                i++;
            } // while
        }
        else{
            printf("\nlink list 1 is empty.\n");
        }
        

        if (first2 != NULL)
        {
            struct node *save2 = first2;
            int i = 1;
            printf("\nsecond link list :\n");
            while (save2 !=NULL)
            {
                printf("value of Node %d : %d\n", i, save2->info);
                save2 = save2 -> link;
            }//while
        }
        else{
            printf("\nlink list 2 is empty.\n");
        }
}
void main(){
    while(1){
        printf("\nenter the your choice.\n1.enter new node in first link list.\n2.enter new node in second link list.\n3.display both link list.\n4.check whether they are same.\n5.exit\n");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            first1 = InsertNewNode(first1);
            break;

        case 2:
            first2 = InsertNewNode(first2);
            break;

        case 3:
            Display();
            break;

        case 4:
            Check();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\ninvalid choice.\n");
            break;
        }
    }//while
}//main
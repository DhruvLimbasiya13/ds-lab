#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link ;
};

struct node *first = NULL ;

void main(){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    int x ;

    printf("enter the info of new node :");
    scanf("%d",&x);

    newNode -> info = x ;
    newNode -> link = first ;
    first = newNode ;


    printf("info of newNode : %d\n",newNode -> info);
    printf("link of newNode : %d",newNode -> link);

}
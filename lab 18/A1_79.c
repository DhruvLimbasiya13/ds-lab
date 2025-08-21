#include<stdio.h>
struct node{
    int value ;
    struct node * left ;
    struct node * right ;
};

struct node *create_node(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}


void main(){
    int total_nodes;
    int preTraversal[total_nodes] ;
    int postTraversal[total_nodes];
    int choice  , start = 0, end = (total_nodes - 1);

    printf("\nenter the number of nodes you want in tree : ");
    scanf("%d",&total_nodes);

    printf("\nenter the nodes values in preorder : ");
    for (int i = 0; i < total_nodes; i++)
    {
        scanf("%d",&preTraversal[i]);
    }
    printf("\nenter the nodes values in preorder : ");
    for (int i = 0; i < total_nodes; i++)
    {
        scanf("%d",&postTraversal[i]);
    }
    constructPreorder();
}
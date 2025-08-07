#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

struct node *create_node(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert_node(int value, struct node *root)
{
    if (root == NULL)
    {
        root = create_node(value);
        return root;
    }
    else
    {
        if (root->value < value)
        {
            root->right = insert_node(value, root->right);
            return root;
        }
        else
        {
            root->left = insert_node(value, root->left);
            return root;
        }
    }
}

struct node *find_min(struct node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct node *delete_node(int value, struct node *root)
{
    if (root == NULL)
    {
        printf("Value not found.\n");
        return NULL;
    }

    if (value < root->value)
    {
        root->left = delete_node(value, root->left);
    }
    else if (value > root->value)
    {
        root->right = delete_node(value, root->right);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = find_min(root->right);
            root->value = temp->value;
            root->right = delete_node(temp->value, root->right);
        }
    }

    return root;
}

int Check_for_same(struct node *root1, struct node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if(root1 == NULL || root2 == NULL){
        return 0 ;
    }
    if (root1->value != root2->value)
    {
        return 0;
    }
    return (Check_for_same(root1->left, root2->left) && Check_for_same(root1->right, root2->right));



}

void main()
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int choice, value;

    while (1)
    {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert Node Into Tree 1\n");
        printf("2. Insert Node Into Tree 2\n");
        printf("3. Delete Node Into Tree 1\n");
        printf("4. Delete Node Into Tree 2\n");
        printf("5. check for Same or Not\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root1 = insert_node(value, root1);
            break;

        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root2 = insert_node(value, root2);
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root1 = delete_node(value, root1);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root2 = delete_node(value, root2);
            break;

        case 5:
            int flag = Check_for_same(root1, root2);
            if (flag)
            {
                printf("\nTrees are Same.\n");
            }
            else{
                printf("\nTrees are not Same.\n");
            }
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

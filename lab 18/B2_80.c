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

struct node* find_min(struct node* root) {
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



void search_node(int value, struct node *root)
{
    if (root == NULL)
    {
        printf("\nvalue not found.\n");
    }
    else if (root->value == value)
    {
        printf("%d value found", value);
    }
    else
    {
        if (root->value < value)
        {
            search_node(value, root->right);
        }
        else
        {
            search_node(value, root->left);
        }
    }
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder_traversal(root->left);
        printf("%d ,", root->value);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ,", root->value);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ,", root->value);
    }
}

int smallest(struct node* root){
    if (root == NULL)
    {
        printf("\ntree is empty.");
    }
    else if (root -> left == NULL)
    {
        return root -> left -> value ;
    }
    else{
        return smallest(root-> left);
    }
}

int largest(struct node* root){
    if (root == NULL)
    {
        printf("\ntree is empty.");
    }
    else if (root -> right == NULL)
    {
        return root -> right -> value ;
    }
    else{
        return smallest(root-> right);
    }
}

void main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n---- Binary Search Tree Menu ----\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Smallest Node\n");
        printf("8. largest Node\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert_node(value, root);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = delete_node(value, root);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search_node(value, root);
            break;

        case 4:
            printf("Inorder: ");
            inorder_traversal(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder: ");
            preorder_traversal(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder: ");
            postorder_traversal(root);
            printf("\n");
            break;

        case 7:
            int smallestNode = smallest(root) ;
            printf("Smallest Value in Tree :  %d " , smallestNode);
            printf("\n");
            break;

        case 8:
            int largestNode = largest(root) ;
            printf("largest Value in Tree :  %d " , largestNode);
            printf("\n");
            break;

        case 9:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

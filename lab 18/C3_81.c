#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

struct Node
{
    char name[MAX_LEN];
    char phoneNumber[10];
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(const char *name, const char *phone)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phone);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *addEntry(struct Node *node, const char *name, const char *phone)
{
    if (node == NULL)
    {
        return createNode(name, phone);
    }

    int cmp = strcmp(name, node->name);
    if (cmp < 0)
    {
        node->left = addEntry(node->left, name, phone);
    }
    else if (cmp > 0)
    {
        node->right = addEntry(node->right, name, phone);
    }
    else
    {
        printf("An entry with this name already exists.\n");
    }
    return node;
}

struct Node *findMin(struct Node *node)
{
    while (node != NULL && node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct Node *removeEntry(struct Node *node, const char *name)
{
    if (node == NULL)
    {
        printf("Contact not found.\n");
        return NULL;
    }

    int cmp = strcmp(name, node->name);
    if (cmp < 0)
    {
        node->left = removeEntry(node->left, name);
    }
    else if (cmp > 0)
    {
        node->right = removeEntry(node->right, name);
    }
    else
    {
        if (node->left == NULL)
        {
            struct Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct Node *temp = node->left;
            free(node);
            return temp;
        }

        struct Node *temp = findMin(node->right);
        strcpy(node->name, temp->name);
        strcpy(node->phoneNumber, temp->phoneNumber);
        node->right = removeEntry(node->right, temp->name);
    }
    return node;
}

void search(struct Node *node, const char *name)
{
    if (node == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    int cmp = strcmp(name, node->name);
    if (cmp == 0)
    {
        printf("Phone Number: %s\n", node->phoneNumber);
    }
    else if (cmp < 0)
    {
        search(node->left, name);
    }
    else
    {
        search(node->right, name);
    }
}

void listAscending(struct Node *node)
{
    if (node != NULL)
    {
        listAscending(node->left);
        printf("  - %s: %s\n", node->name, node->phoneNumber);
        listAscending(node->right);
    }
}

void listDescending(struct Node *node)
{
    if (node != NULL)
    {
        listDescending(node->right);
        printf("  - %s: %s\n", node->name, node->phoneNumber);
        listDescending(node->left);
    }
}

void main()
{
    struct Node *root = NULL;
    int choice;
    char name[MAX_LEN];
    char phone[10];

    do
    {
        printf("\n===== Phone Book Menu =====");
        printf("\n1. Add New Entry");
        printf("\n2. Remove Entry");
        printf("\n3. Search Phone Number");
        printf("\n4. List All Entries (A-Z)");
        printf("\n5. List All Entries (Z-A)");
        printf("\n6. Exit");
        printf("\n===========================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter name: ");
            scanf("%49s", name);
            printf("Enter phone number: ");
            scanf("%9s", phone);
            root = addEntry(root, name, phone);
            printf("Entry added successfully!\n");
            break;
        case 2:
            printf("Enter name to remove: ");
            scanf("%49s", name);
            root = removeEntry(root, name);
            printf("Entry removed successfully (if it existed).\n");
            break;
        case 3:
            printf("Enter name to search: ");
            scanf("%49s", name);
            search(root, name);
            break;
        case 4:
            if (root == NULL)
            {
                printf("Phone book is empty.\n");
            }
            else
            {
                printf("\n--- Phone Book Entries (A-Z) ---\n");
                listAscending(root);
                printf("--------------------------------\n");
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("Phone book is empty.\n");
            }
            else
            {
                printf("\n--- Phone Book Entries (Z-A) ---\n");
                listDescending(root);
                printf("--------------------------------\n");
            }
            break;
        case 6:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
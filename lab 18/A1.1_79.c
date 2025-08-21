#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* constructTree(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h) return NULL;

    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (*preIndex < size && l <= h) {
        int i = search(post, l, h, pre[*preIndex]);
        if (i <= h) {
            root->left = constructTree(pre, post, preIndex, l, i, size);
            root->right = constructTree(pre, post, preIndex, i + 1, h - 1, size);
        }
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int pre[n], post[n];
    printf("Enter preorder sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    printf("Enter postorder sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int preIndex = 0;
    struct Node* root = constructTree(pre, post, &preIndex, 0, n - 1, n);

    printf("Inorder traversal of constructed tree: ");
    inorder(root);
    printf("\n");
}

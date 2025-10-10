#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create() {
    int x;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    printf("Enter left child of %d:\n", x);
    n->left = create();
    printf("Enter right child of %d:\n", x);
    n->right = create();
    return n;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = create();
    printf("Inorder Traversal: ");
    inorder(root);
    return 0;
}

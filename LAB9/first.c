#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

void preorder(Node* root) {
    if (!root) return;
    Node* stack[100]; int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        Node* curr = stack[top--];
        printf("%d ", curr->data);
        if (curr->right) stack[++top] = curr->right;
        if (curr->left)  stack[++top] = curr->left;
    }
}

void inorder(Node* root) {
    Node* stack[100]; int top = -1; Node* curr = root;
    while (curr || top >= 0) {
        while (curr) { stack[++top] = curr; curr = curr->left; }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void postorder(Node* root) {
    if (!root) return;
    Node* s1[100], *s2[100]; int top1=-1, top2=-1;
    s1[++top1] = root;
    while (top1 >= 0) {
        Node* curr = s1[top1--];
        s2[++top2] = curr;
        if (curr->left)  s1[++top1] = curr->left;
        if (curr->right) s1[++top1] = curr->right;
    }
    while (top2 >= 0) printf("%d ", s2[top2--]->data);
}

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int depth(Node* root) {
    if (!root) return 0;
    int l = depth(root->left), r = depth(root->right);
    return (l > r ? l : r) + 1;
}

void printParent(Node* root, int key, Node* parent) {
    if (!root) return;
    if (root->data == key) {
        if (parent) printf("Parent of %d is %d\n", key, parent->data);
        else printf("%d is root (no parent)\n", key);
        return;
    }
    printParent(root->left, key, root);
    printParent(root->right, key, root);
}

int printAncestors(Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");
    printf("Tree depth: %d\n", depth(root));
    printf("Leaf count: %d\n", countLeaves(root));
    printParent(root, 5, NULL);
    printf("Ancestors of 5: "); printAncestors(root, 5); printf("\n");
    return 0;
}

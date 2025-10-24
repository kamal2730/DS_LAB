#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

struct QueueNode {
    struct Node* tnode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Queue* createQ() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->tnode = node; temp->next = NULL;
    if (q->rear == NULL) q->front = q->rear = temp;
    else { q->rear->next = temp; q->rear = temp; }
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    struct Node* n = temp->tnode;
    free(temp);
    return n;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;
    struct Queue* q = createQ();
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* cur = dequeue(q);
        printf("%d ", cur->data);
        if (cur->left) enqueue(q, cur->left);
        if (cur->right) enqueue(q, cur->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Level Order Traversal: ");
    levelOrder(root);
    return 0;
}

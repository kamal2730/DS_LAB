#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear) rear->next = newNode;
    rear = newNode;
    if (front == NULL) front = newNode;
}

int dequeue() {
    if (front == NULL) return -1;
    Node* temp = front;
    int val = front->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

int main() {
    for (int i = 0; i < 5; i++) enqueue(i + 1);
    for (int i = 0; i < 5; i++) printf("Dequeued: %d\n", dequeue());
    return 0;
}

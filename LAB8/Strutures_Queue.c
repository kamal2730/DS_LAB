#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int age;
    int priority;
} Patient;

typedef struct Node {
    Patient data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(Patient p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = p;
    newNode->next = NULL;
    if (rear) rear->next = newNode;
    rear = newNode;
    if (front == NULL) front = newNode;
}

Patient dequeue() {
    if (front == NULL) return (Patient){"", 0, 0};
    Node* temp = front;
    Patient p = front->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return p;
}

int main() {
    Patient p1 = {"John", 30, 1};
    Patient p2 = {"Alice", 25, 2};
    enqueue(p1);
    enqueue(p2);
    for (int i = 0; i < 2; i++) {
        Patient p = dequeue();
        printf("Patient: %s, Age: %d, Priority: %d\n", p.name, p.age, p.priority);
    }
    return 0;
}

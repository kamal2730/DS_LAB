#include <stdio.h>
#define SIZE 5

typedef struct {
    int data;
    int priority;
} Element;

Element pq[SIZE];
int count = 0;

void enqueue(int data, int priority) {
    if (count == SIZE) {
        printf("Queue is full!\n");
        return;
    }

    int i = count - 1;
    // Keep array sorted by priority (highest first)
    while (i >= 0 && pq[i].priority < priority) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    count++;
    printf("Inserted %d with priority %d\n", data, priority);
}

void dequeue() {
    if (count == 0) {
        printf("Queue is empty!\n");
        return;
    }
    // Since highest priority is at front
    printf("Deleted element %d with priority %d\n", pq[0].data, pq[0].priority);
    for (int i = 0; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }
    count--;
}

void display() {
    if (count == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue (sorted):\n");
    for (int i = 0; i < count; i++) {
        printf("Data: %d  Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    enqueue(10, 2);
    enqueue(30, 1);
    enqueue(20, 3);
    display();
    dequeue();
    display();
    return 0;
}

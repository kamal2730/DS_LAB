#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % MAX == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
}

int dequeue() {
    if (front == -1) return -1;
    int val = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return val;
}

int main() {
    for (int i = 0; i < 5; i++) enqueue(i + 1);
    for (int i = 0; i < 5; i++) printf("Dequeued: %d\n", dequeue());
    return 0;
}

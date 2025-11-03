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
    pq[count].data = data;
    pq[count].priority = priority;
    count++;
    printf("Inserted %d with priority %d\n", data, priority);
}

void dequeue() {
    if (count == 0) {
        printf("Queue is empty!\n");
        return;
    }

    int highestPriorityIndex = 0;
    for (int i = 1; i < count; i++) {
        if (pq[i].priority > pq[highestPriorityIndex].priority)
            highestPriorityIndex = i;
    }

    printf("Deleted element %d with priority %d\n", pq[highestPriorityIndex].data, pq[highestPriorityIndex].priority);

    // Shift elements left
    for (int i = highestPriorityIndex; i < count - 1; i++) {
        pq[i] = pq[i + 1];
    }
    count--;
}

void display() {
    if (count == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue (unsorted):\n");
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

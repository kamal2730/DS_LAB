
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
typedef struct {
    int id;
    char name[20];
} Task;

Task queue[MAX];
int front = -1, rear = -1;

void enqueue(Task t) {
    if ((rear + 1) % MAX == front) return;
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = t;
}

Task dequeue() {
    Task t = {0};
    if (front == -1) return t;
    t = queue[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return t;
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        Task t = {rand() % 100, "Doc"};
        enqueue(t);
    }
    for (int i = 0; i < 5; i++) {
        Task t = dequeue();
        printf("Printing %d\n", t.id);
    }
    return 0;
}

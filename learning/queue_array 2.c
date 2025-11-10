// Question 1 — Array-Based Queue (Printer Simulation)
// Write a C program to simulate a printer queue using an array-based queue implementation.
// Each print job contains:
// int doc_id
// char doc_name[50]
// Tasks should arrive either randomly or through user input.
// Implement the following:
// enqueue() to add a print job to the queue
// dequeue() to simulate printing in FIFO order
// Display the queue after each operation

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAX_QUEUE_SIZE 10
typedef struct job{
    int doc_id;
    char doc_name[50];
} job;
int front=-1,rear=-1;
struct job queue[MAX_QUEUE_SIZE];
int isfull(){
    return rear==MAX_QUEUE_SIZE-1;
}
int isempty(){
    return (front==-1);
}
void enqueue(struct job element){
    if(isfull()){
        printf("isfull");
        return;
    }
    if(isempty()){
        front+=1;
        rear=front;
        queue[rear]=element;
    }else{
        queue[++rear]=element;
    }
}
job* dequeue(){
    job *ele=malloc(sizeof(job));
    if(isempty()){
        printf("isempty");
        return ele;
    }
    if(front==rear){
        ele=&queue[front];
        front=rear=-1;
    }else{
        ele=&queue[front++];
    }
    return ele;
}


void display() {
    if (isempty()) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nCurrent Print Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("  [%d] %s\n", queue[i].doc_id, queue[i].doc_name);
    }
}

int main() {
    int choice;
    job j;
    job *printed;

    while (1) {
        printf("\n--- Printer Queue Menu ---\n");
        printf("1. Add print job\n");
        printf("2. Print next job\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter document ID: ");
                scanf("%d", &j.doc_id);
                getchar();
                printf("Enter document name: ");
                fgets(j.doc_name, 50, stdin);
                j.doc_name[strcspn(j.doc_name, "\n")] = '\0'; // remove newline
                enqueue(j);
                break;

            case 2:
                printed = dequeue();
                if (!isempty())
                    printf("Printing: %s (ID: %d)\n", printed->doc_name, printed->doc_id);
                free(printed);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
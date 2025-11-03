#include <stdio.h>
#define MAX 5

int queue[MAX];

int front=-1,rear=-1;

int isFull(){
    return (rear==MAX-1);
}
int isEmpty(){
    return front==-1;
}
void enqueue(int ele){
    if(isFull()) return;
    if(front==-1) front=0;
    queue[++rear]=ele;
    printf("Enqueued:%d \n",ele);
}
int dequeue(){
    if(isEmpty()){return -1;}
    int val=queue[front];
    if(front==rear) front=rear=-1;
    else front++;
    return val;
}
int print_queue(){
    for(int i=0;i<MAX;i++) printf("%d ",queue[i]);
    printf("\n");
}

int main(){
     printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
    int choice, ele, val;
    while(1){
        printf("Enter your choice: ");
        if(scanf("%d", &choice)!=1){
            // invalid input, clear stdin
            int c; while((c=getchar())!='\n' && c!=EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch(choice){
            case 1:
                printf("Enter element to enqueue: ");
                if(scanf("%d", &ele)!=1){
                    int c; while((c=getchar())!='\n' && c!=EOF);
                    printf("Invalid input.\n");
                    break;
                }
                enqueue(ele);
                break;
            case 2:
                val = dequeue();
                if(val==-1) printf("Queue is empty. Nothing to dequeue.\n");
                else printf("Dequeued: %d\n", val);
                break;
            case 3:
                if(isEmpty()){
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue contents: ");
                    for(int i=front;i<=rear;i++){
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
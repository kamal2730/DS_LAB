#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

int queue[MAX_QUEUE_SIZE];
int front=0,rear=0;
int isfull(){
    return ((rear+1)%MAX_QUEUE_SIZE)==front;
}
int isempty(){
    return (front==rear);
}
void enqueue(int val){
    if(isfull()){
        printf("its full");
    }else{
        queue[rear]=val;
        rear=((rear+1)%MAX_QUEUE_SIZE);
    }
}
int dequeue(){
    if(isempty()){
        printf("isempty");
        exit(1);
    }
        int ele=queue[front];
        front=(front+1)%MAX_QUEUE_SIZE;
    return ele;
}
int main(){
    enqueue(5);
    enqueue(10);
    printf("dequeue %d %d",dequeue(),dequeue());
    return 0;
}
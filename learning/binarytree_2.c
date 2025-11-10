#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *left,*right;
} Node;
typedef struct{
    Node* items[100];
    int front;
    int rear;
}Queue;

void enqueue(Queue* queue,Node* ele){
    if(queue->front==-1){
        queue->items[0]=ele;
        queue->front=queue->rear=0;
        return;
    }
    queue->items[++queue->rear]=ele;
}
int isempty(Queue* queue){
    return queue->front==-1;
}
Node* dequeue(Queue* queue){
    if(!isempty(queue)){
        Node* val=queue->items[queue->front++];
        if(queue->front>queue->rear) queue->front=queue->rear=-1;
        return val;
    }
    
}

Node* create_node(int val){
    Node* nn=(Node*)malloc(sizeof(struct node));
    nn->val=val;
    nn->left=nn->right=NULL;
    return nn;
}
Node* create_n(){
    int x=0;
    scanf("%d",&x);
    if(x==-1) return NULL;
    Node*nn=create_node(x);
    printf("Left child of %d:",x);
    nn->left=create_n();
    printf("right child of %d:",x);
    nn->right=create_n();
    return nn;
}
void levelorder_traversal(Node*root){
    if(!root) return;
    Queue* queue=malloc(sizeof(Queue));
    queue->front=-1;
    queue->rear=-1;

    enqueue(queue,root);
    while (!isempty(queue))
    {
        int n=queue->rear-queue->front+1;
        for(int i=0;i<n;i++){
            Node* curr=dequeue(queue);
            printf("%d\t",curr->val);
            if(curr->left) enqueue(queue,curr->left);
            if(curr->right) enqueue(queue,curr->right);
        }
        printf("\n");
    }
    free(queue);
}
int main(){
    Node* root=create_n();
    levelorder_traversal(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100
typedef struct Node{
    int v;
    struct Node* next;
} Node;

Node* list[MAX_LIST_SIZE];
int visited[MAX_LIST_SIZE];
int v_no;
Node* create_node(int v){
    Node* nn=malloc(sizeof(Node));
    nn->v=v;
    nn->next=NULL;
    return nn;
}
void add_edge(int src,int dest){
    Node* nn=create_node(dest);
    nn->next=list[src];
    list[src]=nn;

    //Un-directed
    nn=create_node(src);
    nn->next=list[dest];
    list[dest]=nn;
}
void display(){
    for(int i=0;i<v_no;i++){
        printf("%d:",i);
        Node *temp=list[i];
        while(temp){
            printf("%d \t",temp->v);
            temp=temp->next;
        }
        printf("\n");
    }
}
void dfs(int v){
    visited[v]=1;
    Node* temp=list[v];
    printf("%d\t",v);
    while (temp){
        if(!visited[temp->v]){
            dfs(temp->v);
        }
        temp=temp->next;
    }
}
void bfs(int start){
    for(int i=0;i<v_no;i++) visited[i]=0;
    int queue[MAX_LIST_SIZE];
    int front=0,rear=0;
    visited[start]=1;
    queue[rear++]=start;
    while (front<rear)
    {
        Node* curr=list[front++];
        printf("%d",curr->v);
        Node* temp=list[curr->v];
        while (temp){
            if(!visited[temp->v]){
                visited[temp->v]=1;
                queue[rear++]=temp->v;
            }
            temp=temp->next;
        }
        
    }
    
}
int main(){
    printf("Enter number of v\n");
    scanf("%d",&v_no);
    for(int i=0;i<v_no;i++) list[i]=NULL;
    for(int i=0;i<v_no;i++){
        int c_no;
        printf("enter number of connected nodes of %d:\n",i);
        scanf("%d",&c_no);
        printf("Enter conected nodes of %d:\n",i);
        for(int j=0;j<c_no;j++){
            int c_n;
            scanf("%d",&c_n);
            add_edge(i,c_n);
        }
    }
    printf("Display:\n");
    display();
    for(int i=0;i<v_no;i++) visited[i]=0;
    dfs(0);
    return 0;
}
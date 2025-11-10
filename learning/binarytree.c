#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *left,*right;
} Node;
typedef struct{
    Node* items[100];
    int top;
}Stack;

Node* create_node(int val){
    Node* nn=(Node*)malloc(sizeof(struct node));
    nn->val=val;
    nn->left=nn->right=NULL;
    return nn;
}
void inorder_iterative(Node* root){
    Stack* stack=malloc(sizeof(Stack));
    stack->top=-1;
    Node* curr=root;
    while (stack->top!=-1||curr){
        while(curr) {stack->items[++stack->top]=curr;curr=curr->left;}
        curr=stack->items[stack->top--];
        printf("%d\t",curr->val);
        curr=curr->right;
    }
    free(stack);
}
void preorder_iterative(Node* root){
    //PLR
    Stack* stack=malloc(sizeof(Stack));
    stack->top=-1;
    stack->items[++stack->top]=root;
    while(stack->top!=-1){
        Node* curr=stack->items[stack->top--];
        printf("%d\t",curr->val);
        if(curr->right) stack->items[++stack->top]=curr->right;
        if(curr->left) stack->items[++stack->top]=curr->left;
    }
}
void postorder_iterative(Node* root){
    if(!root) return;
    Stack* s1 = malloc(sizeof(Stack));
    Stack* s2 = malloc(sizeof(Stack));
    s1->top = s2->top = -1;
    s1->items[++s1->top] = root;
    while (s1->top != -1) {
        Node* curr = s1->items[s1->top--];
        s2->items[++s2->top] = curr;
        if (curr->left)
            s1->items[++s1->top] = curr->left;
        if (curr->right)
            s1->items[++s1->top] = curr->right;
    }
    while (s2->top != -1) {
        printf("%d\t", s2->items[s2->top--]->val);
    }
    free(s1);
    free(s2);
}
int print_parent(Node* root,Node* parent,int key){
    if(!root) return -1;
    if(root->val==key){
        if(parent) printf("Parent of %d is %d",root->val,parent->val);
        else printf("its root node");
        return 1;
    }
    if(print_parent(root->left,root,key)) return 1;
    if( print_parent(root->right,root,key)) return 1;
}
int max(int x, int y){
    return x>y?x:y;
}
int height(Node* root){
    if (root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
int leaf_nodes(Node* root){
    if(!root) return 0;
    if(!root->left && !root->right){
        return 1;
    }
    return leaf_nodes(root->right)+leaf_nodes(root->left);
}
int print_ancestors(Node* root,int key){
    if(!root) return 0;
    if(root->val==key) return 1;
    if(print_ancestors(root->left,key)||print_ancestors(root->right,key)){
        printf("%d\t",root->val);
        return 1;
    }
    return 0;
}

int main(){
    Node* root=create_node(55);
    root->left=create_node(45);
    root->right=create_node(35);
    root->left->left=create_node(25);
    root->left->right=create_node(15);
    root->right->left=create_node(25);
    root->right->right=create_node(15);
    root->right->right->left=create_node(69);
    printf("inorder:\n");
    inorder_iterative(root);
    printf("\npreorder:\n");
    preorder_iterative(root);
    printf("\npostorder:\n");
    postorder_iterative(root);
    printf("\n");
    print_parent(root,NULL,45);
    printf("\nheight:%d",height(root));
    printf("\nleafNodes:%d",leaf_nodes(root));
    printf("\nancestors:\n");
    print_ancestors(root,69);
    return 0;
}
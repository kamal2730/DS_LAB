#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int val,height;
    struct Node*left,*right;
}Node;

int max(int x,int y){
    return x>y?x:y;
}
Node* create_node(int val){
    Node* nn=malloc(sizeof(Node));
    nn->height=1;
    nn->left=nn->right=NULL;
    nn->val=val;
    return nn;
}
int height(Node* root){
    if(root==NULL) return 0;
    return root->height;
}
Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* t=y->left;
    y->left=x;
    x->right=t;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
Node* rightRotate(Node* x){
    Node* y=x->left;
    Node* t=y->right;
    y->right=x;
    x->left=t;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
Node* insert(Node*root,int val){
    if(!root) return create_node(val);
    else if(val<root->val) root->left=insert(root->left,val);
    else if(val>root->val) root->right=insert(root->right,val);
    else return root;

    root->height=max(height(root->left),height(root->right))+1;

    int balance=height(root->left)-height(root->right);
    if(balance>1 && val<root->left->val){
        // LL
        root=rightRotate(root);
    }else if(balance>1 && val>root->left->val){
        // LR
        root->left=leftRotate(root->left);
        root=rightRotate(root);
    }else if(balance<-1 && val>root->right->val){
        // RR
        root=leftRotate(root);
    }else if(balance<-1 && val<root->right->val){
        // RL
        root->right=rightRotate(root->right);
        root=leftRotate(root);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d\t",root->val);
    inorder(root->right);
}
int main(){
    Node* root = NULL;

    // Insert elements
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
        inorder(root);
        printf("\n");
    }
    return 0;
}

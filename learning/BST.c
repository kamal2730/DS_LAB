#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int val;
    struct Node* left,*right;
} Node;

Node* create_node(int val){
    Node* nn=malloc(sizeof(Node));
    nn->left=nn->right=NULL;
    nn->val=val;
    return nn;
}
Node* insert(Node* root,int val){
    if(!root) return create_node(val);
    if(val<root->val) root->left=insert(root->left,val);
    else if(val>root->val) root->right=insert(root->right,val);
    return root;
}
Node* search(Node* root,int key){
    if(!root) return root;
    if(root->val==key){
        printf("Found");
        return root;
    }
    return key<root->val?search(root->left,key):search(root->right,key);
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d\t",root->val);
    inorder(root->right);
}
Node* min(Node* root){
    while(root->left) root=root->left;
    return root;
}
Node* max(Node* root){
    while(root->right) root=root->right;
    return root;
}
Node* delete(Node* root,int val){
    if(!root) return root;
    if(val<root->val) root->left=delete(root->left,val);
    else if(val>root->val) root->right=delete(root->right,val);
    else{
        if(!root->left){
            Node* temp=root->right;
            free(root);
            root=temp;
        }else if(!root->right){
            Node* temp=root->left;
            free(root);
            root=temp;
            return root;
        }else{
            Node* temp=min(root->right);
            root->val=temp->val;
            root->right=delete(root->right,temp->val);
        }
    }
    return root;  
}

int main(){
    int ch=0;
    Node* root=NULL;
    while(ch!=-1){
        printf("Enter node value to add(-1 to STOP):");
        scanf("%d",&ch);
        if(ch==-1) break;
        root=insert(root,ch);
    }
    inorder(root);
    Node* found = search(root, 69);
    if (found) printf("\nFound: %d\n", found->val);
    else printf("\nNot Found\n");
    printf("\nmin:%d max:%d\n",min(root)->val,max(root)->val);
    return 0;
}
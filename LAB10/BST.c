#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* newNode(int x){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=x; n->left=n->right=NULL;
    return n;
}

Node* insert(Node* r,int x){
    if(!r) return newNode(x);
    if(x<r->data) r->left=insert(r->left,x);
    else if(x>r->data) r->right=insert(r->right,x);
    return r;
}

void inorder(Node* r){ if(r){ inorder(r->left); printf("%d ",r->data); inorder(r->right);} }
void preorder(Node* r){ if(r){ printf("%d ",r->data); preorder(r->left); preorder(r->right);} }
void postorder(Node* r){ if(r){ postorder(r->left); postorder(r->right); printf("%d ",r->data);} }

Node* search(Node* r,int x){
    if(!r||r->data==x) return r;
    return (x<r->data)?search(r->left,x):search(r->right,x);
}

Node* findMin(Node* r){ while(r&&r->left) r=r->left; return r; }
Node* findMax(Node* r){ while(r&&r->right) r=r->right; return r; }

Node* delete(Node* r,int x){
    if(!r) return r;
    if(x<r->data) r->left=delete(r->left,x);
    else if(x>r->data) r->right=delete(r->right,x);
    else{
        if(!r->left){ Node* t=r->right; free(r); return t; }
        else if(!r->right){ Node* t=r->left; free(r); return t; }
        Node* t=findMin(r->right);
        r->data=t->data;
        r->right=delete(r->right,t->data);
    }
    return r;
}

int main(){
    Node* root=NULL;
    int a[]={50,30,20,40,70,60,80},n=7;
    for(int i=0;i<n;i++) root=insert(root,a[i]);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    int key=40;
    printf("Search %d: %s\n",key, search(root,key)?"Found":"Not Found");
    printf("Min: %d\n", findMin(root)->data);
    printf("Max: %d\n", findMax(root)->data);

    root=delete(root,50);
    printf("Inorder after deleting 50: "); inorder(root); printf("\n");
    return 0;
}

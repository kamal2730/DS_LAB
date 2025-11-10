#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 10
typedef struct Node{
    int val;
    struct Node* next;
} Node;

Node *top=NULL;
Node* create_node(int v){
    Node* nn=malloc(sizeof(Node));
    nn->val=v;
    return nn;
}
void push(int val){
    if (top==NULL) {
        top= create_node(val);
        return;
    }
    Node* nn=create_node(val);
    nn->next=top;
    top=nn;
}
int pop(){
    if (top==NULL) return -1;
    Node*temp=top;
    int val=top->val;
    top=top->next;
    free(temp);
    return val;
}
int peek(){ return top->val;}
int precedence(char x){
    //BODMAS
    if(x=='+'||x=='-'){
        return 2;
    }else if(x=='/'||x=='*'){
        return 1;
    }
    return 0;
}
char* infix_postfix(char* infix){
    char* postfix=malloc(MAX_SIZE*sizeof(char));
    int k=0;
   
    for(int i=0;infix[i];i++){
        char c=infix[i];
        if(isalnum(c)) postfix[k++]=infix[i];
        else if(infix[i]=='(') push(infix[i]);
        else if(infix[i]==')'){
            while(top && top->val!='(') postfix[k++]=pop();
            pop();
        }else{
            while(top && precedence(top->val)>precedence(infix[i])) postfix[k++]=pop();
            push(infix[i]);
        } 
    }
    while(top) postfix[k++]=pop();
    postfix[k] = '\0';
    return postfix;

}
int evaluate_postfix(char* postfix){
    for(int i=0;postfix[i];i++){
        char c=postfix[i];
        if(isdigit(c)) push(c-'0');
        else{
            int op1=pop();
            int op2=pop();
            switch(c){
                case '+':
                    push(op2+op1);
                    break;
                case '-':
                    push(op2-op1);
                    break;
                case '*':
                    push(op2*op1);
                    break;
                case '/':
                    push(op2/op1);
                    break;
                default:
                    printf("issue");
            }
        }
    }
    return (int)pop();
}
int main(){
    char infix[] = "3+(2*5)-8";
    char *postfix=infix_postfix(infix);
    printf("Postfix: %s\n",postfix);
    printf("value:%i",evaluate_postfix(postfix));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  10

struct stack{
    int top;
    char items[MAX_SIZE];
};
int isfull(struct stack* stk){
    if(stk->top==MAX_SIZE-1){return 1;}
    return 0;
}
int isempty(struct stack* stk){
    if(stk->top==-1){return 1;}
    return 0;
}
char peek(struct stack* stk){
    if(!isempty(stk)) return stk->items[stk->top];
    return -1;
}
void push(struct stack* stk,char ele){
    if(!isfull(stk)){
        stk->items[++stk->top]=ele;
    }else{
        printf("stack is full \n");
    }
}
char pop(struct stack* stk){
    char key;
    if(!isempty(stk)) {
        key=stk->items[stk->top];
        stk->top--;
    }else return '\0';
    return key;

}
int main(){
    struct stack* stk=malloc(sizeof(struct stack));
    stk->top=-1;
    char input[MAX_SIZE];
    fgets(input,MAX_SIZE,stdin);
    printf("\nInput:%s\n",input);
    for (int i=0;input[i]!='\0'&& !isfull(stk);i++) {
        // push(stk,input[i]);
        printf("Input[%d]:%c\n",i,input[i]);
        if(input[i]=='{'||input[i]=='('||input[i]=='['){
            push(stk,input[i]);
            printf("pushed\n");
        }else if(input[i]=='}'||input[i]==')'||input[i]==']'){
            char key=pop(stk);
            int flag=0;
            if(key=='\0') flag=1;
            switch(key){
                case '{':
                    if(input[i]!='}') flag=1;
                    break;
                case '[':
                    if(input[i]!=']') flag=1;
                    break;
                case '(':
                    if(input[i]!=')') flag=1;
                    break;
            }
            if(flag==1){
                printf("invalid");
                return -1;
            }
        }
    }
    if(isempty(stk)){
        printf("valid");
    }else{
        printf("invalid");
    }
    return 0;
}
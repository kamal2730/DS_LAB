#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE  5

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
    }
    return key;

}
int main(){
    struct stack *reversed=malloc(sizeof(struct stack));
    reversed->top=-1;
    char input[MAX_SIZE];
    // scanf("%s",input);
    fgets(input, MAX_SIZE, stdin);
    for(int i=0;input[i]!='\0' && !isfull(reversed);i++){
        push(reversed,input[i]);
    }
    for(int i=0;!isempty(reversed);i++){
        // printf("%c",pop(reversed));
        if(input[i]!=pop(reversed)){
            printf("not palindrome");
            return 1;
        }
    }
    printf("palindrome");
    return 0;
}
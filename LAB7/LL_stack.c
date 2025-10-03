#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) return -1;
    struct Node* temp = top;
    char popped = top->data;
    top = top->next;
    free(temp);
    return popped;
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top && top->data != '(') postfix[k++] = pop();
            pop();
        } else {
            while (top && precedence(top->data) >= precedence(c)) postfix[k++] = pop();
            push(c);
        }
    }
    while (top) postfix[k++] = pop();
    postfix[k] = '\0';
}

int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) push(c - '0');
        else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char infix[] = "3+(2*5)-8";
    char postfix[100];
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);
    return 0;
}

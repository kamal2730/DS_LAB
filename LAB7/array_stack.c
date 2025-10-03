#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) stack[++top] = c;
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0';
}

int is_palindrome(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) push(tolower(str[i]));
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != pop()) return 0;
    }
    return 1;
}

int is_balanced(char* expression) {
    for (int i = 0; expression[i]; i++) {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[') push(c);
        else if (c == ')' || c == '}' || c == ']') {
            char top_char = pop();
            if ((c == ')' && top_char != '(') || (c == '}' && top_char != '{') || (c == ']' && top_char != '[')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char input[MAX];
    printf("Enter a string for palindrome check: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (is_palindrome(input)) printf("The string is a palindrome.\n");
    else printf("The string is not a palindrome.\n");

    printf("Enter an expression for parentheses balance check: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (is_balanced(input)) printf("The parentheses are balanced.\n");
    else printf("The parentheses are not balanced.\n");

    return 0;
}

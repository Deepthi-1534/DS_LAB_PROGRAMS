#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100


char stack[MAX_SIZE];
int top = -1;


void push(char data) {
    if (top == MAX_SIZE - 1) {
        printf("Overflow stack!\n");
        return;
    }
    top++;
    stack[top] = data;
}


char pop() {
    if (top == -1) {
        printf("Empty stack!\n");
        return '\0';
    }
    char data = stack[top];
    top--;
    return data;
}


int is_matching_pair(char char1, char char2) {
    if ((char1 == '(' && char2 == ')') ||
        (char1 == '[' && char2 == ']') ||
        (char1 == '{' && char2 == '}')) {
        return 1;
    }
    return 0;
}


int is_balanced(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == '(' || text[i] == '[' || text[i] == '{') {
            push(text[i]);
        } else if (text[i] == ')' || text[i] == ']' || text[i] == '}') {
            if (top == -1) {
                return 0; 
            } else if (!is_matching_pair(pop(), text[i])) {
                return 0; 
            }
        }
    }
    return top == -1; 
}


int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}


int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


void infix_to_postfix(char *infix, char *postfix) {
    int i, j = 0;
    char ch;
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch; 
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else if (is_operator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    if (!is_balanced(infix)) {
        printf("Error: The expression has unbalanced parentheses.\n");
        return 1;
    }

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

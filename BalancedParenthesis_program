#include <stdio.h>
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
    } else {
        return 0;
    }
}


int is_balanced(char* text) {
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

   
    return (top == -1);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (is_balanced(expression)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is not balanced.\n");
    }

    return 0;
}

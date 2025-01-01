typedef struct {
    char items[200];  
    int top;
} Stack;


void init(Stack* stack) {
    stack->top = -1;
}


void push(Stack* stack, char c) {
    stack->items[++(stack->top)] = c;
}


void pop(Stack* stack) {
    if (stack->top >= 0) {
        --(stack->top);
    }
}


bool backspaceCompare(char* s, char* t) {
    Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

   
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '#') {
            pop(&stack1);  
        } else {
            push(&stack1, s[i]);
        }
    }

   
    for (int i = 0; i < strlen(t); ++i) {
        if (t[i] == '#') {
            pop(&stack2);  
        } else {
            push(&stack2, t[i]);
        }
    }

    
    if (stack1.top != stack2.top) {
        return false;
    }

    
    for (int i = 0; i <= stack1.top; ++i) {
        if (stack1.items[i] != stack2.items[i]) {
            return false;
        }
    }

    return true;
}

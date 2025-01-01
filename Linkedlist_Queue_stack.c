#include <stdio.h>
#include <stdlib.h>

// Name: Deepthi M
// USN: 1BM23CS088

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL)
        return -1;
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct Stack* stack) {
    if (stack->top == NULL)
        return -1;
    return stack->top->data;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}

int isEmptyStack(struct Stack* stack) {
    return stack->top == NULL;
}

int isEmptyQueue(struct Queue* queue) {
    return queue->front == NULL;
}

void displayStack(struct Stack* stack) {
    struct Node* temp = stack->top;
    printf("Stack :  ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    printf("Queue : ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Stack stack;
    struct Queue queue;
    initStack(&stack);
    initQueue(&queue);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Stack after pushing :\n");
    displayStack(&stack);

    printf("Pop from stack: %d\n", pop(&stack));
    displayStack(&stack);

    enqueue(&queue, 100);
    enqueue(&queue, 200);
    enqueue(&queue, 300);
    printf("Queue after enqueuing :\n");
    displayQueue(&queue);

    printf("Dequeue from queue: %d\n", dequeue(&queue));
    displayQueue(&queue);

    return 0;
}

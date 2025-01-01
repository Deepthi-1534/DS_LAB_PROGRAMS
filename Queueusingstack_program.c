#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct {
    int array1[MAX];
    int array2[MAX];
    int top1;
    int top2;
    
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->top1 = -1;  
    queue->top2 = -1;  
    return queue;
    
}

void myQueuePush(MyQueue* obj, int x) {
     if (obj->top1 == MAX - 1) 
     {
        printf("Queue is full\n");
        return;
     }
    obj->array1[++(obj->top1)] = x; 
    
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1)
     { 
        if (obj->top1 == -1) 
        { 
            printf("Queue is empty\n");
            return -1;
        }
        while (obj->top1 != -1)
         {
            obj->array2[++(obj->top2)] = obj->array1[(obj->top1)--];  
        }
    }
    return obj->array2[(obj->top2)--];  
    
}

int myQueuePeek(MyQueue* obj) {
     if (obj->top2 == -1)
      {  
        if (obj->top1 == -1) 
        {
            printf("Queue is empty\n");
            return -1;
        }
        while (obj->top1 != -1) 
        {
            obj->array2[++(obj->top2)] = obj->array1[(obj->top1)--];
        }
    }
    return obj->array2[obj->top2];
    
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
    
}

void myQueueFree(MyQueue* obj) {
    free(obj);
    
}

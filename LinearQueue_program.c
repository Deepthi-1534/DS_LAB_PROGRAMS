#include <stdio.h>
#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;


void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}


void insert() {
    int add_item;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0; 
        }
        printf("Insert the element in queue: ");
        scanf("%d", &add_item);
        rear++;
        queue_array[rear] = add_item;
        printf("Inserted: %d\n", add_item);
    }
}


void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue_array[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

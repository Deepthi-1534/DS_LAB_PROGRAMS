#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void Enqueue(int item) {
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    ptr->data = item;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        printf("\nNode with data %d inserted.\n", item);
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\nNode with data %d inserted.\n", item);
    }
}

void Dequeue() {
    struct node* ptr;
    if (head == NULL) {
        printf("\nList is empty, nothing to dequeue.\n");
    } else {
        ptr = head;
        head = ptr->next;
        printf("\nNode with data %d deleted from the beginning.\n", ptr->data);
        free(ptr);
    }
}

void printList() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nCurrent list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                Enqueue(value);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

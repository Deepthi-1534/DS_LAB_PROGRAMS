#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertBefore(struct Node** head, int targetData, int newData) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != targetData) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", targetData);
        return;
    }
    struct Node* newNode = createNode(newData);
    if (temp == *head) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deleteNode(struct Node** head, int data) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, targetData, newData;
     printf(“Deepthi M \n 1BM23CS088”);
    while (1) {
        printf("\nMenu:\n");
        printf("1. Append node\n");
        printf("2. Insert node before a specific node\n");
        printf("3. Delete node by value\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                printf("Enter the target node's data to insert before: ");
                scanf("%d", &targetData);
                printf("Enter the new node's data: ");
                scanf("%d", &newData);
                insertBefore(&head, targetData, newData);
                break;
            case 3:
                printf("Enter the data of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

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
    ptr->data = item;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        printf("\nNode inserted");
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
        printf("\nNode inserted");
    }
}

void Dequeue() {
    struct node* ptr;
    if (head == NULL) {
        printf("\nList is empty");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning...");
    }
}

void printList() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    printList();
    Dequeue();
    printList();
    return 0;
}

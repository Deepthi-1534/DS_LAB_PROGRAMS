#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void reverse(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(struct Node* head) {
    struct Node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next)
            temp = temp->next;
        temp->next = head2;
    }
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    printf("Deepthi M \n1BM23CS088\n");

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, item;

    do {
        printf("\nENTER THE OPERATION YOU WANT TO PERFORM:\n");
        printf("1. Insert for first node\n");
        printf("2. Insert for second node\n");
        printf("3. Concatenate\n");
        printf("4. Reverse\n");
        printf("5. Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value for first node: ");
                scanf("%d", &item);
                append(&list1, item);
                break;
            case 2:
                printf("Enter value for second node: ");
                scanf("%d", &item);
                append(&list2, item);
                break;
            case 3:
                concatenate(&list1, list2);
                printf("Concatenated List: ");
                printList(list1);
                break;
            case 4:
                reverse(&list1);
                printf("Reversed List 1: ");
                printList(list1);
                reverse(&list2);
                printf("Reversed List 2: ");
                printList(list2);
                break;
            case 5:
                sort(list1);
                printf("Sorted List 1: ");
                printList(list1);
                sort(list2);
                printf("Sorted List 2: ");
                printList(list2);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. \n");
        }
    } while (choice != 6);

    return 0;
}

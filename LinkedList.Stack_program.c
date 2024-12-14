#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* NODE;

NODE getnode() {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}

NODE insert_beg(int item, NODE first) {
    NODE new = getnode();
    new->value = item;
    new->next = first;
    return new;
}

NODE insert_end(int item, NODE first) {
    NODE new_end = getnode();
    new_end->value = item;
    new_end->next = NULL;
    if (first == NULL) {
        return new_end;
    }
    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_end;
    return first;
}

NODE insert_pos(NODE first, int item, int pos) {
    NODE new = getnode();
    new->value = item;
    new->next = NULL;
    if (first == NULL && pos == 1) {
        return new;
    }
    if (pos < 1) {
        free(new);
        return first;
    }
    int count = 1;
    NODE current = first, prev = NULL;
    while (count < pos && current != NULL) {
        prev = current;
        current = current->next;
        count++;
    }
    if (count != pos) {
        free(new);
        return first;
    }
    new->next = current;
    if (prev != NULL) {
        prev->next = new;
    } else {
        return new;
    }
    return first;
}

NODE delete_first(NODE first) {
    if (first == NULL) {
        return NULL;
    }
    NODE temp = first;
    first = first->next;
    free(temp);
    return first;
}

NODE delete_end(NODE first) {
    if (first == NULL) {
        return NULL;
    }
    if (first->next == NULL) {
        free(first);
        return NULL;
    }
    NODE prev = NULL, last = first;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
    return first;
}

NODE delete_value(NODE first, int value) {
    if (first == NULL) {
        return NULL;
    }
    NODE current = first, prev = NULL;
    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return first;
    }
    if (prev == NULL) {
        first = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return first;
}

void display(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

NODE sort_list(NODE first) {
    if (first == NULL || first->next == NULL) {
        return first;
    }
    NODE i, j;
    int temp;
    for (i = first; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->value > j->value) {
                temp = i->value;
                i->value = j->value;
                j->value = temp;
            }
        }
    }
    return first;
}

NODE concatenate(NODE first1, NODE first2) {
    if (first1 == NULL) {
        return first2;
    }
    NODE temp = first1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = first2;
    return first1;
}

NODE reverse(NODE first) {
    NODE prev = NULL, current = first, next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    NODE first = NULL;
    NODE second = NULL;
    int choice, item, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete by Value\n");
        printf("7. Display\n");
        printf("8. Sort List\n");
        printf("9. Concatenate Lists\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &item);
                first = insert_beg(item, first);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &item);
                first = insert_end(item, first);
                break;
            case 3:
                printf("Enter value and position to insert: ");
                scanf("%d %d", &item, &pos);
                first = insert_pos(first, item, pos);
                break;
            case 4:
                first = delete_first(first);
                break;
            case 5:
                first = delete_end(first);
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                first = delete_value(first, item);
                break;
            case 7:
                display(first);
                break;
            case 8:
                first = sort_list(first);
                printf("List after sorting: ");
                display(first);
                break;
            case 9:
                printf("Enter values for second list (end with -1): ");
                while (1) {
                    scanf("%d", &item);
                    if (item == -1) break;
                    second = insert_end(item, second);
                }
                first = concatenate(first, second);
                printf("List after concatenation: ");
                display(first);
                break;
            case 10:
                first = reverse(first);
                printf("List after reversal: ");
                display(first);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

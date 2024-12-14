#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* NODE;


NODE getnode() {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node==NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return new_node;
}


NODE insert_pos(NODE first, int item, int pos) {
    NODE new = getnode();
    new->value = item;
    new->next = NULL;

    if (first == NULL && pos == 1) {
        return new;
    }

    if (pos < 1) {
        printf("INVALID POSITION\n");
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
        printf("INVALID POSITION\n");
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


NODE delete_first(NODE first) {
    if (first == NULL) {
        printf("LINKED LIST IS EMPTY\n");
        return NULL;
    }

    NODE temp = first;
    first = first->next;
    free(temp);
    return first;
}


NODE delete_end(NODE first) {
    if (first == NULL) {
        printf("LINKED LIST IS EMPTY\n");
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
        printf("LINKED LIST IS EMPTY\n");
        return NULL;
    }

    NODE current = first, prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("VALUE NOT FOUND\n");
        return first;
    }

    if (prev == NULL) {
        first = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return first;
} void display(NODE first)
{ NODE temp;

    if(first==NULL)
    {

        printf("linked list is empty");
        return;
    }
     temp=first;
    while(temp!=NULL)
    {

        printf("%d",temp->value);
        temp=temp->next;
    }
}
int main() {
    NODE first = NULL;
    int choice, item, pos;

    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete by Value\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice. \n");
        }
    } 

    return 0;
}










#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data);
int pop(struct node **top);
void displayStack(struct node *top);

int main() {
    struct node *top = NULL;
    int choice, data;

    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                displayStack(top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = *top;
    *top = newNode;

    printf("Pushed element: %d\n", data);
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    struct node *temp = *top;
    int data = temp->data;

    *top = (*top)->next;
    free(temp);

    return data;
}

void displayStack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}


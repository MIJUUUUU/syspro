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
    int input;

    while (1) {
        if (scanf("%d", &input) != 1) {
           displayStack(top);
            break;
        }

        push(&top, input);
    }

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

    printf("Print stack\n");

    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}


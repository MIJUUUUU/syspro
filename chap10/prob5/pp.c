#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data);
int delete(struct node **head, struct node **tail);
void displayQueue(struct node *head);

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int input;

    while (1) {
        if (scanf("%d", &input) != 1) {
            displayQueue(head);
            break;
        }

        addq(&head, &tail, input);
    }

    return 0;
}

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    if (*head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct node *temp = *head;
    int data = temp->data;

    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
    }

    free(temp);
    return data;
}

void displayQueue(struct node *head) {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Print queue\n");

    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}


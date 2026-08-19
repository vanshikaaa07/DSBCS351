#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void deleteKth(struct Node **head, int k) {
    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Check if list is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If k = 1, delete first node
    if (k == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Move to kth node
    for (int i = 1; i < k && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Check if position is invalid
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    // Delete kth node
    prev->next = temp->next;
    free(temp);
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Creating nodes
    struct Node *n1 = malloc(sizeof(struct Node));
    struct Node *n2 = malloc(sizeof(struct Node));
    struct Node *n3 = malloc(sizeof(struct Node));
    struct Node *n4 = malloc(sizeof(struct Node));

    n1->data = 10;
    n1->next = n2;

    n2->data = 20;
    n2->next = n3;

    n3->data = 30;
    n3->next = n4;

    n4->data = 40;
    n4->next = NULL;

    head = n1;

    printf("Before deletion:\n");
    display(head);

    // Delete node at kth position
    deleteKth(&head, 3);

    printf("After deletion:\n");
    display(head);

    return 0;
}
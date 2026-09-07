#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Delete from beginning
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // If there is only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    // Move to second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete from a given position
void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Position 1 means first node
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node *temp = *head;

    // Move to the node before the position
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    // Check if position exists
    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);
}

// Insert at end (for creating the list)
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the list
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;

    // Creating the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List: ");
    display(head);

    // Delete from beginning
    deleteFromBeginning(&head);
    printf("After deletion from beginning: ");
    display(head);

    // Delete from end
    deleteFromEnd(&head);
    printf("After deletion from end: ");
    display(head);

    // Delete from position 2
    deleteAtPosition(&head, 2);
    printf("After deletion from position 2: ");
    display(head);

    return 0;
}

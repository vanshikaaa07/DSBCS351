#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert node at the end
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

// Reverse the linked list
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move prev and current forward
        prev = current;
        current = next;
    }

    // Update head
    *head = prev;
}

// Display the linked list
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

    printf("Original Linked List: ");
    display(head);

    // Reverse the linked list
    reverse(&head);

    printf("Reversed Linked List: ");
    display(head);

    return 0;
}

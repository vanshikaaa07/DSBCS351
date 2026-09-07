#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert at beginning
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    temp = *head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
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

    // Insertion at beginning
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    // Insertion at end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List: ");
    display(head);

    return 0;
}

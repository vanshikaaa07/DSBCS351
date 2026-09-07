#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Insert a node at the end
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

// Search an element
void search(struct Node *head, int key) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element %d not found in the linked list.\n", key);
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

    printf("Linked List: ");
    display(head);

    // Search for an element
    search(head, 30);

    return 0;
}

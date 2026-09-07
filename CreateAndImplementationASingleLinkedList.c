#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    newNode->next = *head;
    *head = newNode;
}

// Delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    free(temp);
}

// Display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("After creating the list:\n");
    display(head);

    // Insert at beginning
    insertAtBeginning(&head, 5);

    printf("\nAfter inserting 5 at beginning:\n");
    display(head);

    // Insert at end
    insertAtEnd(&head, 40);

    printf("\nAfter inserting 40 at end:\n");
    display(head);

    // Delete from beginning
    deleteFromBeginning(&head);

    printf("\nAfter deleting first node:\n");
    display(head);

    return 0;
}

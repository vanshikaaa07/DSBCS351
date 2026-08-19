

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function to traverse the linked list
void traverse(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating nodes
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traverse the linked list
    traverse(head);

    // Free allocated memory
    free(head);
    free(second);
    free(third);

    return 0;
}
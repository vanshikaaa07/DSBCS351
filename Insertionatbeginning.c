#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode;

    // Create a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Enter data
    printf("Enter data: ");
    scanf("%d", &newNode->data);

    // Insert at beginning
    newNode->next = head;
    head = newNode;

    // Display the linked list
    printf("Linked List: ");
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
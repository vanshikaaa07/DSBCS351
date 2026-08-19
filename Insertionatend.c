#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;

    // Create new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
    }
    else {
        temp = head;

        // Go to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert new node at the end
        temp->next = newNode;
    }

    // Display linked list
    printf("Linked List: ");

    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
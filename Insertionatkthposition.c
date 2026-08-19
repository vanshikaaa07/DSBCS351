#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int n, i, k, data;

    // Create linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Enter position and data
    printf("Enter position (k): ");
    scanf("%d", &k);

    printf("Enter data to insert: ");
    scanf("%d", &data);

    // Create new node
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    // Insertion at beginning
    if (k == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        temp = head;

        // Move to (k-1)th node
        for (i = 1; i < k - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        // Check if position is valid
        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newNode);
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
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
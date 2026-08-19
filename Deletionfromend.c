#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp, *prev;
    int n, i;

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

    // Deletion from end
    if (head == NULL) {
        printf("List is empty!\n");
    }
    else if (head->next == NULL) {
        // Only one node
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        // Reach the last node
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        // Remove last node
        prev->next = NULL;
        free(temp);
    }

    // Display linked list
    printf("Linked List after deletion: ");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}
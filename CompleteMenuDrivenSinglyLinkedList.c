#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted successfully.\n");
}


void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted successfully.\n");
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


void insertAtPosition(struct Node **head, int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = *head;

    for (int i = 1; i < position - 1; i++) {
        if (temp == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("Node deleted successfully.\n");
}


void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted successfully.\n");
        return;
    }

    struct Node *temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    printf("Node deleted successfully.\n");
}


void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    struct Node *temp = *head;

    for (int i = 1; i < position - 1; i++) {
        if (temp->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted successfully.\n");
}


void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void search(struct Node *head, int key) {
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n",
                   key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element %d not found.\n", key);
}


void countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes = %d\n", count);
}


void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;

    printf("Linked list reversed successfully.\n");
}


void freeList(struct Node **head) {
    struct Node *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


int main() {
    struct Node *head = NULL;

    int choice;
    int data;
    int position;

    while (1) {
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display / Traverse\n");
        printf("8. Search Element\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                insertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);

                insertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insertAtPosition(&head, data, position);
                break;

            case 4:
                deleteFromBeginning(&head);
                break;

            case 5:
                deleteFromEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);

                deleteAtPosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);

                search(head, data);
                break;

            case 9:
                countNodes(head);
                break;

            case 10:
                reverse(&head);
                break;

            case 11:
                freeList(&head);
                printf("Program exited successfully.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

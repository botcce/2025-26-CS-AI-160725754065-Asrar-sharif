#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insertAtBegin(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void insertAtEnd(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    if (head == NULL) {
        head = tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void deleteFromBegin() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Deleted: %d\n", temp->data);

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
    }
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head == tail) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = tail = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        printf("Deleted: %d\n", tail->data);
        free(tail);
        tail = temp;
        tail->next = head;
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("CLL Elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to Head: %d)\n", head->data);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert Begin\n2. Insert End\n3. Delete Begin\n4. Delete End\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBegin(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBegin();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

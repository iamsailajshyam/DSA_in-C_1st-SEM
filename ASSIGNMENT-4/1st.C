// Menu Driven Program for Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

// Function prototypes
void createDoublyLinkedList(int data);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertBeforeNode(int target, int data);
void insertAfterNode(int target, int data);
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterNode(int target);
void deleteEntireList();

// Main function
int main() {
    int choice, data, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the elements\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a given node\n");
        printf("6. Insert after a given node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete the entire list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create the list: ");
                scanf("%d", &data);
                createDoublyLinkedList(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter the target node and data to insert before it: ");
                scanf("%d %d", &target, &data);
                insertBeforeNode(target, data);
                break;
            case 6:
                printf("Enter the target node and data to insert after it: ");
                scanf("%d %d", &target, &data);
                insertAfterNode(target, data);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter the target node to delete after it: ");
                scanf("%d", &target);
                deleteAfterNode(target);
                break;
            case 10:
                deleteEntireList();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to create a doubly linked list
void createDoublyLinkedList(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    head = newNode;
    printf("List created with data: %d\n", data);
}

// Function to display the list
void displayList() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert at the end
void insertAtEnd(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d at the end\n", data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end\n", data);
}

// Function to insert before a given node
void insertBeforeNode(int target, int data) {
    Node *temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found!\n", target);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    printf("Inserted %d before %d\n", data, target);
}

// Function to insert after a given node
void insertAfterNode(int target, int data) {
    Node *temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found!\n", target);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = temp;
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d after %d\n", data, target);
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted node with data %d from the beginning\n", temp->data);
    free(temp);
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    printf("Deleted node with data %d from the end\n", temp->data);
    free(temp);
}

// Function to delete after a given node
void deleteAfterNode(int target) {
    Node *temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node found to delete after %d!\n", target);
        return;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL) {
        delNode->next->prev = temp;
    }
    printf("Deleted node with data %d after %d\n", delNode->data, target);
    free(delNode);
}

// Function to delete the entire list
void deleteEntireList() {
    Node *temp = head;
    while (temp != NULL) {
        Node *nextNode = temp->next;
        printf("Deleting node with data %d\n", temp->data);
        free(temp);
        temp = nextNode;
    }
    head = NULL;
    printf("Entire list deleted\n");
}

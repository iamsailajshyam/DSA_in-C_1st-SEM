// Menu Driven Program for Circular Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

// Function prototypes
void createCircularDoublyLinkedList(int data);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteFromBeginning();
void deleteFromEnd();
void deleteAfterNode(int target);
void deleteEntireList();

// Main function
int main() {
    int choice, data, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular doubly linked list\n");
        printf("2. Display the elements\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete after a given node\n");
        printf("8. Delete the entire list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to create the list: ");
                scanf("%d", &data);
                createCircularDoublyLinkedList(data);
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
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                printf("Enter the target node to delete after it: ");
                scanf("%d", &target);
                deleteAfterNode(target);
                break;
            case 8:
                deleteEntireList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to create a circular doubly linked list
void createCircularDoublyLinkedList(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    head = newNode;
    printf("List created with data: %d\n", data);
}

// Function to display the list
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        printf("Inserted %d at the beginning\n", data);
        return;
    }
    Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
    printf("Inserted %d at the beginning\n", data);
}

// Function to insert at the end
void insertAtEnd(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        head = newNode;
        printf("Inserted %d at the end\n", data);
        return;
    }
    Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    printf("Inserted %d at the end\n", data);
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    if (head->next == head) {
        head = NULL;
    } else {
        Node *tail = head->prev;
        head = head->next;
        head->prev = tail;
        tail->next = head;
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
    Node *tail = head->prev;
    if (tail == head) {
        head = NULL;
    } else {
        Node *prevNode = tail->prev;
        prevNode->next = head;
        head->prev = prevNode;
    }
    printf("Deleted node with data %d from the end\n", tail->data);
    free(tail);
}

// Function to delete after a given node
void deleteAfterNode(int target) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    do {
        if (temp->data == target) {
            Node *delNode = temp->next;
            if (delNode == head) {
                printf("Cannot delete after the last node!\n");
                return;
            }
            temp->next = delNode->next;
            delNode->next->prev = temp;
            printf("Deleted node with data %d after %d\n", delNode->data, target);
            free(delNode);
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with data %d not found!\n", target);
}

// Function to delete the entire list
void deleteEntireList() {
    if (head == NULL) {
        printf("List is already empty!\n");
        return;
    }
    Node *temp = head;
    do {
        Node *nextNode = temp->next;
        printf("Deleting node with data %d\n", temp->data);
        free(temp);
        temp = nextNode;
    } while (temp != head);
    head = NULL;
    printf("Entire list deleted\n");
}

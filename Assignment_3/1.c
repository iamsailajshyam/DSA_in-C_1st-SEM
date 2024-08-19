#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Initialize the head of the list to NULL
struct node *head = NULL;

// Function to insert a node at the beginning of the list
void pushbeg() {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nEnter data to push: ");
    scanf("%d", &n->data);
    n->next = head;
    head = n;
}

// Function to insert a node at the end of the list
void pushend() {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nEnter data to push: ");
    scanf("%d", &n->data);
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        struct node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

// Function to delete a node from the beginning of the list
void popbeg() {
    if (head == NULL) {
        printf("\nUnderflow");
        return;
    }
    struct node *del = head;
    printf("\n%d has been deleted", del->data);
    head = head->next;
    free(del);
}

// Function to delete a node from the end of the list
void popend() {
    if (head == NULL) {
        printf("\nUnderflow");
        return;
    } else if (head->next == NULL) {
        popbeg();
        return;
    } else {
        struct node *del = head;
        while (del->next->next != NULL) {
            del = del->next;
        }
        printf("\n%d has been deleted", del->next->data);
        free(del->next);
        del->next = NULL;
    }
}

// Function to insert a node at a specific position
void pushpos() {
    int pos;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos < 0) {
        printf("\nInvalid position.");
        return;
    }
    if (pos == 0) {
        pushbeg();
        return;
    }
    struct node *n = (struct node*)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("\nMemory allocation failed.");
        return;
    }
    printf("\nEnter data to push: ");
    scanf("%d", &n->data);
    struct node *p = head;
    for (int i = 1; i < pos && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("\nPosition out of bounds.");
        free(n);
    } else {
        n->next = p->next;
        p->next = n;
    }
}

// Function to delete a node from a specific position
void poppos(int pos) {
    if (head == NULL) {
        printf("\nUnderflow");
        return;
    }
    if (pos < 0) {
        printf("\nInvalid position.");
        return;
    }
    if (pos == 0) {
        popbeg();
        return;
    }
    struct node *p = head;
    for (int i = 1; i < pos && p->next != NULL; i++) {
        p = p->next;
    }
    if (p->next == NULL) {
        printf("\nPosition out of bounds.");
        return;
    }
    struct node *del = p->next;
    p->next = p->next->next;
    printf("\n%d has been deleted", del->data);
    free(del);
}

// Function to delete a node with specific data
void popdata() {
    if (head == NULL) {
        printf("\nUnderflow");
        return;
    }
    int d;
    printf("\nEnter data to delete: ");
    scanf("%d", &d);
    struct node *p = head;
    struct node *prev = NULL;
    while (p != NULL && p->data != d) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("\nData not found");
        return;
    }
    if (prev == NULL) {
        head = p->next;
    } else {
        prev->next = p->next;
    }
    printf("\n%d has been deleted", p->data);
    free(p);
}

// Function to display the list
void disp() {
    if (head == NULL) {
        printf("\nEmpty");
        return;
    }
    struct node *p = head;
    while (p != NULL) {
        printf("%d --> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    printf("1. pushbeg\n2. pushend\n3. popbeg\n4. popend\n5. pushpos\n6. poppos\n7. popdata\n8. disp\n0. exit");
    while (1) {
        int ch;
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: pushbeg(); break;
            case 2: pushend(); break;
            case 3: popbeg(); break;
            case 4: popend(); break;
            case 5: pushpos(); break;
            case 6: {
                int pos;
                printf("\nEnter position: ");
                scanf("%d", &pos);
                poppos(pos);
                break;
            }
            case 7: popdata(); break;
            case 8: disp(); break;
            case 0: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}


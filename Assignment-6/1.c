#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// 1) Stack Using Array
int stack[MAX];
int top = -1;

void pushArray(int element) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = element;
    printf("%d pushed to stack\n", element);
}

void popArray() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}

void peekArray() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

void displayArray() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// 2) Stack Using Linked List
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void pushLinkedList(int element) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = head;
    head = newNode;
    printf("%d pushed to stack\n", element);
}

void popLinkedList() {
    if (head == NULL) {
        printf("Stack underflow!\n");
        return;
    }
    struct Node *temp = head;
    printf("%d popped from stack\n", head->data);
    head = head->next;
    free(temp);
}

void peekLinkedList() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", head->data);
}

void displayLinkedList() {
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Stack elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 3) Convert infix to postfix
int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

void infixToPostfix(char *infix) {
    char stack[MAX];
    int top = -1;
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

// 4) Convert infix to prefix
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void infixToPrefix(char *infix) {
    reverseString(infix);

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char prefix[MAX];
    infixToPostfix(infix);
    strcpy(prefix, infix);

    reverseString(prefix);
    printf("Prefix Expression: %s\n", prefix);
}

// 5) Evaluate postfix expression
int evaluatePostfix(char *postfix) {
    int stack[MAX], top = -1;

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            switch (ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

// 6) Evaluate prefix expression
int evaluatePrefix(char *prefix) {
    int stack[MAX], top = -1;
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            stack[++top] = ch - '0';
        } else {
            int a = stack[top--];
            int b = stack[top--];
            switch (ch) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
            }
        }
    }

    return stack[top];
}

// 7) Fibonacci series using recursion
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacci(int n) {
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// 8) Tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    char infix[MAX] = "a+b*c";
    char postfix[MAX] = "abc*+";
    char prefix[MAX] = "+a*bc";

    // Stack using array demo
    pushArray(10);
    pushArray(20);
    popArray();
    peekArray();
    displayArray();

    // Stack using linked list demo
    pushLinkedList(30);
    pushLinkedList(40);
    popLinkedList();
    peekLinkedList();
    displayLinkedList();

    // Infix to postfix
    infixToPostfix(infix);

    // Infix to prefix
    infixToPrefix(infix);

    // Evaluate postfix
    printf("Postfix Evaluation: %d\n", evaluatePostfix(postfix));

    // Evaluate prefix
    printf("Prefix Evaluation: %d\n", evaluatePrefix(prefix));

    // Fibonacci
    printFibonacci(10);

    // Tower of Hanoi
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
struct Element {
    char info;
    struct Element *next;
};

// Stack structure
struct StackStruct {
    struct Element *head;
};

// Function to initialize an empty stack
void initStack(struct StackStruct *stk) {
    stk->head = NULL;
}

// Function to check if the stack is empty
bool isEmptyStack(struct StackStruct *stk) {
    return (stk->head == NULL);
}

// Function to push a character onto the stack
void pushStack(struct StackStruct *stk, char data) {
    struct Element *newElement = (struct Element *)malloc(sizeof(struct Element));
    if (newElement == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->info = data;
    newElement->next = stk->head;
    stk->head = newElement;
}

// Function to pop a character from the stack
char popStack(struct StackStruct *stk) {
    if (isEmptyStack(stk)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }

    char data = stk->head->info;
    struct Element *temp = stk->head;
    stk->head = stk->head->next;
    free(temp);

    return data;
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infixExp[], char postfixExp[]) {
    struct StackStruct stk;
    initStack(&stk);

    int i = 0, j = 0;

    while (infixExp[i] != '\0') {
        if ((infixExp[i] >= 'a' && infixExp[i] <= 'z') || (infixExp[i] >= 'A' && infixExp[i] <= 'Z')) {
            postfixExp[j++] = infixExp[i++];
        } else if (infixExp[i] == '(') {
            pushStack(&stk, infixExp[i++]);
        } else if (infixExp[i] == ')') {
            while (!isEmptyStack(&stk) && stk.head->info != '(') {
                postfixExp[j++] = popStack(&stk);
            }
            if (!isEmptyStack(&stk) && stk.head->info != '(') {
                printf("Invalid expression.\n");
                exit(EXIT_FAILURE);
            } else {
                popStack(&stk); // Pop '('
                i++;
            }
        } else {
            while (!isEmptyStack(&stk) && getPrecedence(infixExp[i]) <= getPrecedence(stk.head->info)) {
                postfixExp[j++] = popStack(&stk);
            }
            pushStack(&stk, infixExp[i++]);
        }
    }

    while (!isEmptyStack(&stk)) {
        postfixExp[j++] = popStack(&stk);
    }

    postfixExp[j] = '\0'; // Null-terminate the postfix expression
}

// Function to display postfix expression
void showPostfix(char postfixExp[]) {
    printf("Postfix Expression: %s\n", postfixExp);
}

int main() {
    char infixExp[100];
    char postfixExp[100];

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Display Postfix Expression\n");
        printf("3. Close\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infixExp);
                infixToPostfix(infixExp, postfixExp);
                break;
            case 2:
                showPostfix(postfixExp);
                break;
            case 3:
                printf("Closing the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK OPERATIONS MENU ---\n");
        printf("1. Push (Insert Element)\n");
        printf("2. Pop (Delete Element)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option between 1 and 4.\n");
        }
    }
    return 0;
}

void push() {
    int val;
    if (top == MAX - 1) {
        printf("Error: Stack Overflow.\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top == -1) {
        printf("Error: Stack Underflow.\n");
    } else {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Current Stack elements :\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}

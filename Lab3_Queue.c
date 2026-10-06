#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int element);
void delete();
void display();

int main() {
    int choice, value;

    printf("--- Queue Operations Using Array --- \n");
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the integer to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert(int element) {

    if (rear == MAX - 1) {
        printf("Error: Queue Overflow.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;

    }
}

void delete() {

    if (front == -1 || front > rear) {
        printf("Error: Queue Empty.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {

    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Current Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

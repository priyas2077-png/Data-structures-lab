#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the size of the stack

int stack[MAX], top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } else {
        stack[++top] = val;
        printf("%d pushed into stack.\n", val);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                val = pop();
                if (val != -1) printf("Popped: %d\n", val);
                break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// THE RECURSIVE SORTED INSERT FUNCTION
void sortedInsert(int element) {
    // Base case: stack is empty or element is greater than top
    if (top == -1 || element > stack[top]) {
        push(element);
        return;
    }

    // If element is smaller, pop the top
    int temp = pop();
    
    // Recursive call to find the right place
    sortedInsert(element);

    // Push back the popped element
    push(temp);
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;
    printf("--- Sorted Stack Maintenance ---\n");
    while (1) {
        printf("\n1. Insert Element\n2. Display\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                sortedInsert(val);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
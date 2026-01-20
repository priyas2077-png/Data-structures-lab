#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int S[MAX], T[MAX];
int topS = -1, topT = -1;

void pushS(int val) {
    if (topS == MAX - 1) printf("Stack S Overflow\n");
    else S[++topS] = val;
}

int popS() {
    if (topS == -1) return -1;
    return S[topS--];
}

void pushT(int val) {
    if (topT == MAX - 1) printf("Stack T Overflow\n");
    else T[++topT] = val;
}

int popT() {
    if (topT == -1) return -1;
    return T[topT--];
}

void sortStack() {
    while (topS != -1) {
        // 4.1 Pop top from S
        int x = popS();

        // 4.3 While T is not empty and top of T > x
        while (topT != -1 && T[topT] > x) {
            // 4.3.1 & 4.3.2 Pop from T, push back to S
            pushS(popT());
        }
        // 4.4 Push x into T
        pushT(x);
    }

    // 6. Move everything from T back to S so Original Stack is sorted
    while (topT != -1) {
        pushS(popT());
    }
    printf("Stack sorted successfully!\n");
}

void display() {
    if (topS == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Original Stack (Top to Bottom): ");
    for (int i = topS; i >= 0; i--) printf("%d ", S[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1. Push 2. Pop 3. Display 4. SORT 5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); pushS(val); break;
            case 2: val = popS(); if(val != -1) printf("Popped: %d\n", val); break;
            case 3: display(); break;
            case 4: sortStack(); break;
            case 5: exit(0);
        }
    }
    return 0;
}
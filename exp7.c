#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int val) {
    if (top1 < top2 - 1) {
        arr[++top1] = val;
        printf("Pushed %d to Stack 1\n", val);
    } else {
        printf("Stack 1 Overflow!\n");
    }
}

void push2(int val) {
    if (top1 < top2 - 1) {
        arr[--top2] = val;
        printf("Pushed %d to Stack 2\n", val);
    } else {
        printf("Stack 2 Overflow!\n");
    }
}

// ENSURE THIS IS LOWERCASE 'main'
int main() {
    int choice, val;
    printf("1. Push S1\n2. Push S2\n3. Exit\n");
    while(1) {
        printf("Choice: ");
        scanf("%d", &choice);
        if(choice == 3) break;
        printf("Value: ");
        scanf("%d", &val);
        if(choice == 1) push1(val);
        else if(choice == 2) push2(val);
    }
    return 0;
}
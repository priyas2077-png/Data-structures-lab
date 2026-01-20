#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int pos, int element) {
    for (int i = *n - 1; i >= pos - 1; i--) arr[i + 1] = arr[i];
    arr[pos - 1] = element;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    for (int i = pos - 1; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int arr[100], n, choice, pos, element;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter pos & element: ");
                scanf("%d %d", &pos, &element);
                insert(arr, &n, pos, element);
                break;
            case 2:
                printf("Enter pos to delete: ");
                scanf("%d", &pos);
                delete(arr, &n, pos);
                break;
            case 3: display(arr, n); break;
            case 4: exit(0);
        }
    }
    return 0;
}

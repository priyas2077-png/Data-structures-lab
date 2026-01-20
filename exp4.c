#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}

void leftRotate(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main() {
    int arr[100], n, k, i;
    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);
    printf("Enter elements: ");
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    leftRotate(arr, n, k);

    printf("Array after left rotation: ");
    for(i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
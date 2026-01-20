#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
}

int main() {
    int arr[100], n, key, pos;
    printf("Enter n: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter key: "); scanf("%d", &key);
    
    pos = linearSearch(arr, n, key);
    if (pos != -1) printf("Linear Search: Found at %d\n", pos + 1);
    
    sort(arr, n);
    pos = binarySearch(arr, n, key);
    if (pos != -1) printf("Binary Search (Sorted): Found at %d\n", pos + 1);
    
    return 0;
}
#include <stdio.h>

int main() {
    int arr[100], freq[100];
    int n, i, j, count;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency tracker
    }

    for(i = 0; i < n; i++) {
        count = 1;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Mark as counted
            }
        }
        if(freq[i] != 0) freq[i] = count;
    }

    printf("Element | Frequency\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != 0) printf("%d | %d\n", arr[i], freq[i]);
    }
    return 0;
}
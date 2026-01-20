#include <stdio.h>

int main() {
    int arr[100], n, i;
    int max, min, sum = 0, largest, second;
    float avg;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding Max, Min, and Sum
    max = min = arr[0];
    for(i = 0; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
        sum += arr[i];
    }
    avg = (float)sum / n;

    // Finding Second Largest
    largest = second = -2147483648; 
    for(i = 0; i < n; i++) {
        if(arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if(arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    printf("Max: %d\nMin: %d\nSum: %d\nAvg: %.2f\nSecond Largest: %d\n", max, min, sum, avg, second);
    return 0;
}
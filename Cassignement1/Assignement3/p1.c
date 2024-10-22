#include <stdio.h>

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = sumArray(arr, size);

    printf("The sum of all elements in the array is: %d\n", sum);

    return 0;
}

//delete element from particular position
//Time complexity : O(n) [only for delete and shifting not for array input and display]

#include <stdio.h>

int main() {
    int arr[100], n, i, pos;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete (1-based index)
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    // Check valid position
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        // Shift elements to left
        for(i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;  // Reduce size

        // Print updated array
        printf("Array after deletion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
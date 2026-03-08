// insert an element in array in a particular position

//Time Complexity : O(n)
//[only for insert and shifting(not for array input and display)]

#include <stdio.h>

int main() {
    int arr[100], n, i, pos, element;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element and position
    printf("Enter element to insert: ");
    scanf("%d", &element);

    printf("Enter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Validate position
    if(pos < 1 || pos > n + 1) {
        printf("Invalid position!\n");
    } else {
        // Shift elements to right
        for(i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = element;  // Insert element
        n++;  // Increase size

        // Print updated array
        printf("Array after insertion:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
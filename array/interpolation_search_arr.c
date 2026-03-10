//interpolation Search in sorted array
// Time Complexity: O(log n) for search (input reading is O(n))

#include <stdio.h>

int main() {
    int arr[100], n, i, key;
    int low, high, pos;
    int found = 0;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input sorted array
    printf("Enter %d elements (in sorted order):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high && key >= arr[low] && key <= arr[high]) {

        // If only one element
        if(low == high) {
            if(arr[low] == key) {
                printf("Element found at position %d\n", low + 1);
            } else {
                printf("Element not found\n");
            }
            return 0;
        }

        // Interpolation formula
        pos = low + ((key - arr[low]) * (high - low)) 
              / (arr[high] - arr[low]);

        if(arr[pos] == key) {
            printf("Element found at position %d\n", pos + 1);
            found = 1;
            break;
        }
        else if(arr[pos] < key) {
            low = pos + 1;
        }
        else {
            high = pos - 1;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}
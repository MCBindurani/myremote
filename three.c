#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

// Function to perform binary search
int binarySearch(char names[][MAX_LENGTH], int left, int right, char *target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        int result = strcmp(names[mid], target);
        
        // Check if target is present at mid
        if (result == 0) {
            return mid; // Name found
        }

        // If target is greater, ignore left half
        if (result < 0) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    return -1; // Name not found
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH] = {
        "Alice", "Bob", "Charlie", "David", "Eve",
        "Frank", "Grace", "Heidi", "Ivan", "Judy"
    };
    int n = 10; // Number of names
    char target[MAX_LENGTH];

    // Prompt user for the name to search
    printf("Enter the name to search: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0; // Remove newline character

    // Perform binary search
    int result = binarySearch(names, 0, n - 1, target);
    
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int length_of_array, temp;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &length_of_array);

    int arr[length_of_array];
    // Reading array elements
    for(int i = 0; i < length_of_array; i++) {
        printf("Enter %d element:\n", (i+1));
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    // Sorting using pointer arithmetic (Bubble Sort)
    for(int i = 0; i < length_of_array - 1; i++) {
        for(int j = 0; j < length_of_array - i - 1; j++) {
            if(*(ptr + j) > *(ptr + j + 1)) {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    // Displaying sorted array
    printf("Sorted array in ascending order:\n");
    for(int i = 0; i < length_of_array; i++) {
        printf("%d ", *(ptr + i));
    }
}

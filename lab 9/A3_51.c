
#include <stdio.h>
#include <stdlib.h>

void main() {
    int *arr = NULL, num, count = 0, sum = 0;

    while (1) {
        printf("Enter a number (-1 to end): ");
        scanf("%d", &num);

        if (num == -1)
            break;

        int *temp = realloc(arr, (count + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            free(arr);
        }
        arr = temp;

        arr[count] = num;
        sum += num;
        count++;
    }

    printf("\nYou entered %d numbers.\n", count);
    printf("Sum = %d\n", sum);

    free(arr);
}

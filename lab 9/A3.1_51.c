#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, *ptr, sum = 0,i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
    }

    for (i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

	printf("Sum = %d\n", sum);
    free(ptr);
}

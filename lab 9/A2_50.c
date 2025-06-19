#include<stdio.h>
#include<stdlib.h>
void main(){
    int n, *arr;

	printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));

	if (arr == NULL) {
        printf("Memory not allocated.\n");
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }
    
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    free(arr);
}



#include<stdio.h>
void main(){
    int length_0f_array;
    printf("enter how many array you want=");
    scanf("%d",&length_0f_array);

    int a[length_0f_array];
    for (int i=0;i<length_0f_array;i++)
    {
        printf("enter a number=");
        scanf("%d",&a[i]);
    }
    printf("The elements of the array are:\n");
    for(int i = 0; i < length_0f_array; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    int duplicate_found = 0;
    for (int i = 0; i < length_0f_array - 1; i++) {
        for (int j = i + 1; j < length_0f_array; j++) {
            if (a[i] == a[j]) {
                printf("Duplicate found: %d at indices %d and %d\n", a[i], i, j);
                duplicate_found = 1;
            }
        }
    }
    if (!duplicate_found) {
        printf("No duplicates found in the array.\n");
    }
}
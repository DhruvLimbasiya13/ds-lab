#include<stdio.h>
void main(){
    int length_of_array;

    printf("Enter the length of the array: ");
    scanf("%d", &length_of_array);

    int array[length_of_array ];
    
    for(int i = 0; i < length_of_array; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int location;
    printf("Enter the location to delete the element (0 to %d): ", length_of_array);
    scanf("%d", &location);
    if(location < 0 || location > length_of_array) {
        printf("Invalid location!\n");
        return;
    }
    for(int i = location; i < length_of_array; i++) {
        array[i] = array[i + 1];
    }
    length_of_array--;
    printf("Array after deletion: ");
    for(int i = 0; i < length_of_array; i++) {
        printf("%d ", array[i]);
    }
}
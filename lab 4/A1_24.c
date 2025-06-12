#include<stdio.h>
void main(){
    int length_of_array;

    printf("Enter the length of the array: ");
    scanf("%d", &length_of_array);

    int array[length_of_array + 1];
    
    for(int i = 0; i < length_of_array; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int location, value;
    printf("Enter the location to insert the element (0 to %d): ", length_of_array);
    scanf("%d", &location);
    if(location < 0 || location > length_of_array) {
        printf("Invalid location!\n");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    for(int i = length_of_array; i > location; i--) {
        array[i] = array[i - 1];
    }
    array[location] = value;

    printf("Array after insertion: ");
    for(int i = 0; i <= length_of_array; i++) {
        printf("%d ", array[i]);
    }
}
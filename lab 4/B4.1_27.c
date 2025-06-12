#include<stdio.h>
void main(){
    int length_of_array;
    
    printf("Enter the length of the array: ");
    scanf("%d", &length_of_array);

    int array[length_of_array];
    
    printf("enter the element in acending order\n");
    for(int i = 0; i < length_of_array; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    int value;
    
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    // Check if the value exists in the array
    int found = 0;
    for(int i = 0; i < length_of_array; i++) {
        if(array[i] == value) {
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Value %d not found in the array.\n", value);
        return;
    }

    int index = length_of_array;
    for(int i = 0; i < length_of_array; i++){

        if(array[i] >= value) {

            index = i;
            break;
        }
    }

    for(int i = index; i < length_of_array; i++) {
        array[i] = array[i + 1];
    }
    length_of_array--;

    printf("Array after deletion: ");
    for(int i = 0; i < length_of_array; i++) {
        printf("%d ", array[i]);
    }
}
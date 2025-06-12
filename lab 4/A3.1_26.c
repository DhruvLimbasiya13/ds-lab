#include<stdio.h>
void main(){
    int length_of_array;
    
    printf("Enter the length of the array: ");
    scanf("%d", &length_of_array);

    int array[length_of_array + 1];
    
    printf("enter the element in acending order\n");
    for(int i = 0; i < length_of_array; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    
    int value;
    
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    int index = length_of_array;
    for(int i = 0; i < length_of_array; i++){

        if(array[i] > value) {

            index = i;
            break;
        }
    }

    for(int j = length_of_array; j > index;j--) {
                array[j] = array[j - 1];
            }
    
    array[index] = value;

    printf("Array after insertion: ");
    for(int i = 0; i <= length_of_array; i++) {
        printf("%d ", array[i]);
    }
}
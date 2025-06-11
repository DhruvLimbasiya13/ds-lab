#include<stdio.h>
void main(){
    int array_length ;
    printf("Enter the length of the array: ");
    scanf("%d", &array_length);
    int array[array_length];
    //reading the elements of the array
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < array_length; i++){
        scanf("%d", &array[i]);
    }

    // display the elements of the array
    for(int i=0 ; i< array_length; i++){
        printf("%d , ", array[i]);
    }
}
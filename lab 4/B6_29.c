#include<stdio.h>
void main(){
    int length_of_array ;
    printf("enter the number of elements you want :");
    scanf("%d",&length_of_array);

    int first_array[length_of_array] , second_array[length_of_array], third_array[2*length_of_array];

    //scaning array
    for (int i = 0; i < length_of_array; i++)
    {
        printf("enter the element %d of first array :",i+1);
        scanf("%d",&first_array[i]);
    }
    
    for (int i = 0; i < length_of_array; i++)
    {
        printf("enter the element %d of second array :",i+1);
        scanf("%d",&second_array[i]);
    }
    //copying first array
    for (int i = 0; i < length_of_array; i++)
    {
        third_array[i] = first_array[i];
    }

    //copying second array
    for (int i = 0; i< (length_of_array); i++)
    {
        third_array[length_of_array+i] = second_array[i];
    }

    //display all arrays
    for (int i = 0; i < length_of_array; i++)
    {
        printf("%d  ,",first_array[i]);
    }
    
    printf("\n");

    for (int i = 0; i < length_of_array; i++)
    {
        printf("%d  ,",second_array[i]);
    }

    printf("\n");
    for (int i = 0; i < (2*length_of_array); i++)
    {
        printf("%d  ,",third_array[i]);
    }
}
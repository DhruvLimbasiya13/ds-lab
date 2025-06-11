#include<stdio.h>
void main(){
    int first_number, second_number, third_number;
    printf("enter first number: ");
    scanf("%d", &first_number);
    printf("enter second number: ");
    scanf("%d", &second_number);
    printf("enter third number: ");
    scanf("%d", &third_number);

    first_number > second_number ? (first_number > third_number ? printf("The largest number is: %d\n", first_number) :printf("The largest number is: %d\n", third_number)):(second_number > third_number ? printf("The largest number is: %d\n", second_number) : printf("The largest number is: %d\n", third_number));
}
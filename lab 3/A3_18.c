#include<stdio.h>
void main(){
    int first_number = 1 , ending_number , sum = 0;
    float average ;

    printf("enter the last number to calculate the average: ");
    scanf("%d", &ending_number);
    for(int i = first_number; i <= ending_number; i++){
        sum += i;
    }
    average = (float)sum / (ending_number - first_number + 1);
    printf("The average of the numbers from %d to %d is: %.2f\n", first_number, ending_number, average);
}
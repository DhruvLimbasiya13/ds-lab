#include<stdio.h>
void main(){
    int sum=0, ending_number;
    printf("Enter an ending number: ");
    scanf("%d", &ending_number);
    for(int i = 1; i <= ending_number; i++){
        sum= ((i)*(i + 1) )/ 2; // Using the formula for the sum of the first n natural numbers: n(n+1)/2
        // for(int j = 1; j <= i; j++){
        //     sum += j;
        //
    }
    printf("The sum of all numbers from 1 to %d is: %d\n", ending_number, sum);
}
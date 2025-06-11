#include<stdio.h>
void main(){
    int starting_number , ending_number , sum=0;

    printf("Enter the starting number: ");
    scanf("%d",&starting_number);
    printf("Enter the ending number: ");
    scanf("%d",&ending_number);

    for(int i = starting_number; i <=ending_number ; i++){
        sum+=i;
    }
    printf("The sum of the numbers from %d to %d is: %d\n", starting_number, ending_number, sum);
}
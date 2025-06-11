#include<stdio.h>
void main(){
    int number ,i ,sum=0 , r , temp;
    printf("Enter a number: ");
    scanf("%d", &number);
    temp = number;
    while (number > 0) {
        r = number % 10;
        sum += r * r * r;
        number /=10;
    }

    if (temp == sum) {
        printf("%d is an Armstrong number.\n", temp);
    } else {
        printf("%d is not an Armstrong number.\n", temp);
    }
}
#include<stdio.h>
void main(){
    int base ,power , result = 1;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter power: ");
    scanf("%d", &power);
    for(int i = 1; i <= power; i++){
        result *= base;
    }
    printf("%d raised to the power of %d is %d\n", base, power, result);
}
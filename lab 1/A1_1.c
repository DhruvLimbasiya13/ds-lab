#include<stdio.h>
#define PI 3.14159
void main(){
    int radius ;
    float area;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    area = radius * radius * PI;
    printf("area of circle = %f",area);
}
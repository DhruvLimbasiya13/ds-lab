#include<stdio.h>
void main()
{
    int d,years,months,days;

    printf("Enter number of days= ");
    scanf("%d",&d);

    years=(d)/365;
    months=(d-years*365)/30;
    days=(d-years*365-months*30);
    
    printf("Years = %d",years);
    printf("\nMonths = %d",months);
    printf("\nDays = %d",days);
}
#include<stdio.h>
void main()
{
    int sec,hours,minutes,seconds;
    printf("enter seconds=");
    scanf("%d",&sec);
    hours=sec/3600;
    minutes=(sec-(hours*3600))/60;// sec-(hours*3600) can use sec= sec%3600
    seconds=sec-(minutes*60)-(hours*3600);
    printf("%d : %d : %d",hours,minutes,seconds);
}
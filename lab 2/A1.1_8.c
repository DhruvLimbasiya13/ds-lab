#include<stdio.h>
void main()
{
    int num,factorial=1,i;
    printf("enter integer :");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        factorial=factorial*i;
    }
    printf("%d\n",factorial);
}
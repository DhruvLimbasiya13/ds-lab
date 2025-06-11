#include<stdio.h>
void main()
{
    int i=2,n,flag=0;
    printf("enter a number =");
    scanf("%d",&n);
    while (i<n)
    {
        if (n%i==0)
        {
            flag=1;
            break;
        }
        i++;
    }
    if (flag==0)
    {
    printf("%d is a prime number",n);
    }
    else{
    printf("%d is not a prime number",n);
    }
    
}
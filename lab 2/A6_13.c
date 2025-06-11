#include<stdio.h>
void main()
{
    int i=2,starting_number,ending_number,flag=0;
    printf("enter a starting number =");
    scanf("%d",&starting_number);
    printf("enter an ending number =");
    scanf("%d",&ending_number);
    printf("Prime numbers between %d and %d are:\n", starting_number, ending_number);
    for (int n = starting_number; n <= ending_number; n++)
    {
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

}
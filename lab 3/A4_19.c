#include<stdio.h>
void main()
{
    int i,n,max,min;
    printf("enter how many array you want=");
    scanf("%d",&n);

    int a[n];
    for (i=0;i<n;i++)
    {
        printf("enter a number=");
        scanf("%d",&a[i]);
    }
    max=a[0];
    min=a[0];
    for (i=0;i<n;i++)
    {
        if (a[i]>a[max])
        {
            max=i;
        }

        if (a[i]<min)
        {
            min=a[i];
        }
        
    }
    
    printf("max at index =%d\n",max);
    printf("min at index =%d",min);
}
#include<stdio.h>
void main(){
    int length_0f_array;
    printf("enter how many array you want=");
    scanf("%d",&length_0f_array);

    int a[length_0f_array];
    for (int i=0;i<length_0f_array;i++)
    {
        printf("enter a number=");
        scanf("%d",&a[i]);
    }

    int search_number;
    printf("Enter the number you want to search for: ");
    scanf("%d", &search_number);

    int replace_number;
    printf("enter the number you want to replace :");
    scanf("%d",&replace_number);

    int found = 0 ;
    
    for(int i=0 ; i<length_0f_array;i++){
        if (a[i]==search_number)
        {
            printf("found at index : %d",i);
            a[i]=replace_number;
            found=1;
        }
    }
    for (int i=0;i<length_0f_array;i++)
    {
        printf("\n%d" , a[i]);
    }
}

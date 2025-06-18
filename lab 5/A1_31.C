#include<stdio.h>
void main(){
    int first_array[2][2] , second_array[2][2] , third_array[2][2];

    //scaning first array
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("enter element [%d][%d] of first array :", i, j);
            scanf("%d", &first_array[i][j]);
        }
    }

    //scaning second array
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("enter element [%d][%d] of second array :",i,j);
            scanf("%d", &second_array[i][j]);
        }
    }

    //sum of both array
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            third_array[i][j] = first_array[i][j] + second_array[i][j] ;
        }
    }

    // display all arrays
    printf("first array :\n");
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("%d\t",first_array[i][j]);
        }
        printf("\n");
    }
    printf("second array :\n");
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("%d\t",second_array[i][j]);
        }
        printf("\n");
    }

    printf("sum of both array :\n");
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("%d\t",third_array[i][j]);
        }
        printf("\n");
    }
}
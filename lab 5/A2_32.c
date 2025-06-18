#include<stdio.h>
void main(){
    int first_array[3][2] , second_array[2][3] , third_array[3][3];

    //scaning first array
    for(int i =0 ; i<3 ; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("enter element [%d][%d] of first array :", i+1, j+1);
            scanf("%d", &first_array[i][j]);
        }
    }

    //scaning second array
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 3;j++)
        {
            printf("enter element [%d][%d] of second array :",i+1,j+1);
            scanf("%d", &second_array[i][j]);
        }
    }

    //multiplication of first and second array
    for (int  a = 0; a < 3; a++)
    {
        for (int  i = 0; i < 3; i++)
        {
            third_array[a][i] = 0;

            for (int  j = 0; j < 2; j++)
            {
                third_array[a][i] += (first_array[a][j] * second_array [j][i]);
            }
            
        }
        
    }
    
    // display all arrays
    printf("first array :\n");
    for(int i =0 ; i<3; i++){
        for (int j = 0; j < 2;j++)
        {
            printf("%d\t",first_array[i][j]);
        }
        printf("\n");
    }
    printf("second array :\n");
    for(int i =0 ; i<2 ; i++){
        for (int j = 0; j < 3;j++)
        {
            printf("%d\t",second_array[i][j]);
        }
        printf("\n");
    }

    printf("multiplication of both array :\n");
    for(int i =0 ; i<3 ; i++){
        for (int j = 0; j < 3;j++)
        {
            printf("%d\t",third_array[i][j]);
        }
        printf("\n");
    }
}
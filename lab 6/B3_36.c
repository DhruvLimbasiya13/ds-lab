#include<stdio.h>
#include<string.h>

void main(){
    char str[100];
    printf("enter a string of a and b : ");
    scanf("%s",str);

    int countA = 0 , countB = 0 ;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
        {
            countA++;
        }
        else{
            countB++;
        }
    }
    
}
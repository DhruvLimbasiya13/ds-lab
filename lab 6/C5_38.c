#include<stdio.h>
#include<string.h>

#define MAX 1000

char stack[MAX];
int top = -1 ;

void removeStar(char *s){
    for (int i = 0; s[i] != '\0' ; i++)
    {
        if (s[i] == '*')
        {
            top--;
        }
        else{
            stack[++top] = s[i];
        }
        
    }
}

void main(){
    char inputString[MAX];
    printf("enter the string with * :");
    scanf("%s", inputString);

    removeStar(inputString);

    printf("%s",stack);

}

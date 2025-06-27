#include <stdio.h>
#include<string.h>
void main() {
    char str[100];
    char *start, *end;

    printf("Enter a word: ");
    scanf("%s", str);

    // Count length of string
    int length = strlen(str);

    start = str;               // points to first character
    end = str + length - 1;    // points to last character

    int flag=0;
    while(start < end) {
        if(*start != *end) {
            printf("Not a Palindrome\n");
            flag=1;
            break;
        }
        start++;
        end--;
    }
    if(flag==0)
    {printf("Palindrome\n");}
}

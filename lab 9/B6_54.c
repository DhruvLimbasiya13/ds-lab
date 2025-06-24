#include <stdio.h>

int main() {
    char str[100];
    char *start, *end;
    int length = 0;

    printf("Enter a word: ");
    scanf("%s", str); // reads a single word

    // Count length of string
    while(str[length] != '\0') {
        length++;
    }

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

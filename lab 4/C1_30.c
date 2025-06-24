#include <stdio.h>
#include<string.h>
void main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; strlen(str); i++) {
        // If character is lowercase, convert to uppercase
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        // If character is uppercase, convert to lowercase
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }

    printf("Modified string: %s\n", str);
}

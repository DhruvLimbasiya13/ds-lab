#include<stdio.h>
void main(){
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    if(ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z') 
        printf("Invalid input. Please enter an alphabetic character.\n");
        return;
    
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // Convert uppercase to lowercase
    }
    if(ch == 'a'||ch =='e'||ch =='i'||ch =='o'||ch =='u'){
        printf("The character is a vowel.\n");
    } else {
        printf("The character is a consonant.\n");
    }
}
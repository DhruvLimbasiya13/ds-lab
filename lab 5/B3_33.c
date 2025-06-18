#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void main(){
    // to change the value of random evertime as random doesn't change everytime we run the program
    srand(time(0));

    int number_of_words ;

    printf("how many words you want to enter :");
    scanf("%d",&number_of_words);

    //words["dog","cat","monkey"]
    char words[number_of_words][100];

    for (int i = 0; i < number_of_words; i++)
    {
        printf("enter word at place %d :" , i+1);
        scanf("%s",words[i]);
    }

    //generate random number between number of words
    int random_number=rand()%(number_of_words);

    printf("random number : %d ",random_number);
    printf("random word : %s" , words[random_number]);

    char userword[100];

    printf("enter the words for anagram :");
    scanf("%s",userword);

    for (int i = 0; i < strlen(userword[random_number]); i++)
    {
        
    }
    
}
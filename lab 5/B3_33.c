#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void main(){
    // to change the value of random evertime as random doesn't change everytime we run the program
    srand(time(NULL));

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

    printf("random number : %d \n",random_number);
    printf("random word : %s\n" , words[random_number]);

    char userword[100];

    printf("enter the words for anagram :");
    scanf("%s",userword);

    //sort both words and compare

    char temp1[100], temp2[100];

    strcpy(temp1, words[random_number]);
    strcpy(temp2, userword);

    // simple bubble sort for both strings
    int len1 = strlen(temp1);
    int len2 = strlen(temp2);

    if (len1 != len2) {
        printf("Not an anagram (lengths are different)\n");
    } else {
        for (int i = 0; i < len1 - 1; i++) {
            for (int j = i + 1; j < len1; j++) {
                if (temp1[i] > temp1[j]) {
                    char t = temp1[i];
                    temp1[i] = temp1[j];
                    temp1[j] = t;
                }
                if (temp2[i] > temp2[j]) {
                    char t = temp2[i];
                    temp2[i] = temp2[j];
                    temp2[j] = t;
                }
            }
        }

        if (strcmp(temp1, temp2) == 0) {
            printf("'%s' is an anagram of '%s'\n", userword, words[random_number]);
        } else {
            printf("'%s' is NOT an anagram of '%s'\n", userword, words[random_number]);
        }
    }
}
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>     // Added this for time() function
#include<string.h>   // Added this for strlen() function
#include<ctype.h>    // Added this for tolower() function

// Function to check if two words are anagrams
int checkAnagram(char word1[], char word2[]) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    // If lengths are different, they can't be anagrams
    if (len1 != len2) {
        return 0;
    }
    
    // Convert both words to lowercase for comparison
    char temp1[100], temp2[100];
    for(int i = 0; i < len1; i++) {
        temp1[i] = tolower(word1[i]);
        temp2[i] = tolower(word2[i]);
    }
    temp1[len1] = '\0';
    temp2[len2] = '\0';
    
    // Count frequency of each character
    int count[26] = {0}; // For 26 letters
    
    // Count characters in first word
    for (int i = 0; i < len1; i++) {
        if (temp1[i] >= 'a' && temp1[i] <= 'z') {
            count[temp1[i] - 'a']++;
        }
    }
    
    // Subtract characters from second word
    for (int i = 0; i < len2; i++) {
        if (temp2[i] >= 'a' && temp2[i] <= 'z') {
            count[temp2[i] - 'a']--;
        }
    }
    
    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

void main(){
    // to change the value of random evertime as random doesn't change everytime we run the program
    srand(time(0));

    int number_of_words;

    printf("How many words you want to enter: ");
    scanf("%d", &number_of_words);

    // words["dog","cat","monkey"]
    char words[number_of_words][100];

    for (int i = 0; i < number_of_words; i++) {
        printf("Enter word at place %d: ", i+1);
        scanf("%s", words[i]);
    }

    // generate random number between number of words
    int random_number = rand() % number_of_words;

    printf("Random number: %d\n", random_number);
    printf("Random word: %s\n", words[random_number]);
    
    printf("Enter an anagram of this word: ");

    char user_word[100];
    scanf("%s", user_word);

    // Check if the entered word is an anagram
    if (checkAnagram(words[random_number], user_word)) {
        printf("Correct! '%s' is an anagram of '%s'\n", user_word, words[random_number]);
    } else {
        printf("Sorry! '%s' is NOT an anagram of '%s'\n", user_word, words[random_number]);
    }
}

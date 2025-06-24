#include <stdio.h>
#include <string.h>

void main() {
    int totalNames, i, j;
    char temp[100];

    printf("Enter number of names: ");
    scanf("%d", &totalNames);

    char names[totalNames][100];

    printf("Enter %d names:\n", totalNames);
    for(i = 0; i < totalNames; i++) {
        scanf("%s", names[i]);
    }

    // Alphabetical sorting using Bubble Sort and strcmp
    for(i = 0; i < totalNames - 1; i++) {
        for(j = i + 1; j < totalNames; j++) {
            if(strcmp(names[i], names[j]) > 0)// if first letter of name[i] come after (comes after it in dictionary order) first letter of name[j]  then return positive value 
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nNames in alphabetical order:\n");
    for(i = 0; i < totalNames; i++) {
        printf("%s\n", names[i]);
    }

}
